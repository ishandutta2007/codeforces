#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 22222;
                        
int n, m, t, ans, cur;
int tt[3];
int a[MAXN];
vector<pair<pii, int> > q;
int num[MAXN], l, r, pos[MAXN];
bool f;

int main() { 

	scanf("%d%d%d\n", &n, &m, &t);
	forn(i, n) {
		scanf("%d:%d:%d\n", &tt[0], &tt[1], &tt[2]);
		a[i] = tt[0] * 60 * 60 + tt[1] * 60 + tt[2];
		q.pb({{a[i], 1}, i});
		q.pb({{a[i] + t, 0}, i});	
	}
	
	sort(all(q));
	
	f = 0;
	ans = 0;
	l = 0;
	r = -1;
	forn(i, q.size()) {
		if (q[i].X.Y == 0) {
			num[pos[q[i].Y]]--;
			if (num[pos[q[i].Y]] == 0)
				l++;
		} else {
			if (r -	l + 1 == m) {
				f = 1;	
			    pos[q[i].Y] = r;
			    num[r]++;
			} else {
				r++;
				pos[q[i].Y] = r;
				num[r]++;		
			}
		}

		if (r -	l + 1 == m) {
			f = 1;
		}
	}
	
	ans = r + 1;
	if (!f)
		cout << "No solution";
	else {
		cout << ans << '\n';
		forn(i, n) {
			cout << pos[i] + 1 << '\n';
		}		
	}		
	return 0;
}