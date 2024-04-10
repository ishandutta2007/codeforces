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
const int MAXN = 100500;
        
string L = "aeiouy";

int n;
int a[MAXN], p[MAXN];
ll ans;
ll all[MAXN];

int LtoR[MAXN];
set<pair<int, ll>> seg;

int main() {

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	
	memset(LtoR, -1, sizeof(LtoR));
	seg.insert({-INF, 0});
	seg.insert({INF, 0});
	
	ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		all[i] = ans;

		int pos = p[i];	
		LtoR[pos] = pos;
		
		pair<int, ll> cSeg = {pos, a[pos]};
		auto cur = *seg.lower_bound({pos, 0});
		if (cur.X != INF && pos + 1 == cur.X) {
			LtoR[pos] = LtoR[cur.X];
			seg.erase(cur);
			cSeg.Y += cur.Y;
		}
		
		auto ptr = seg.lower_bound({pos, 0});
		ptr--;
		cur = *ptr;
		
		if (cur.X != -INF && LtoR[cur.X] + 1 == pos) {
			LtoR[cur.X] = LtoR[pos];
			pos = cur.X;
			cSeg.X = cur.X;
			seg.erase(cur);
			cSeg.Y += cur.Y;				
		}
		
		ans = max(ans, cSeg.Y);
		seg.insert(cSeg);
	}
	
	forn(i, n)
		printf("%I64d\n", all[i]);
	
	return 0;
}