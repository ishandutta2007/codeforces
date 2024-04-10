#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 300500;

int n, k;
ll ans[MAXN];
multiset<pii> segments;
int Q;
pair<pii, pii> queries[2 * MAXN];

int main() {

	Q = 0;
    scanf("%d%d", &n, &k);
    forn(i, n) {
    	int x, y;
    	scanf("%d%d", &x, &y);	
    	
    	queries[Q++] = {{x - k, 0}, {y - k, y}};
    	queries[Q++] = {{x, 1}, {y - k, y}};
    }
        
    sort(queries, queries + Q);
    segments.clear();
    
    for (int i = 0; i < Q - 1; i++) {
    	int L = queries[i].Y.X;
    	int R = queries[i].Y.Y;
    	
		if (queries[i].X.Y == 0) {
			segments.insert({L, 0});
			segments.insert({R, 1});
		} else {
			//auto it = *segments.find({L, 0});
			segments.erase(segments.find({L, 0}));	
			//it = *segments.find({R, 1});
			segments.erase(segments.find({R, 1}));	
		}
		
		ll mult = queries[i + 1].X.X - queries[i].X.X;
		
		if (mult == 0)	
			continue;
			
		//cout << "* " << mult << ":\n";
		
		int open = 0;
		for (auto it = segments.begin(); it != segments.end(); ) {
			//cout << it->X << ' ' << it->Y << '\n';
			if (it->Y == 0)
				open++;
			else
				open--;	

			auto nit = it;
			nit++;	
			
			if (nit == segments.end())
				break;
				
			if (1 <= open && open <= n)
				ans[open] += mult * (nit->X - it->X);
			it = nit;
		}
    }
    
    for (int i = 1; i <= n; i++)
    	printf("%I64d%c", ans[i], " \n"[i == n]);
    	
    return 0;
}