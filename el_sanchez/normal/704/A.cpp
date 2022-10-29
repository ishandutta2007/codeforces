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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 300500;

int n, q;
int t, x;
int p, ans;
vi all, used;
vi lst[MAXN];
int ptr[MAXN];

int main() {

	scanf("%d%d", &n, &q);
	p = 0;
	ans = 0;
	forn(i, q) {
		scanf("%d%d", &t, &x);
		if (t == 1) {
			lst[x].pb(all.size());
			all.pb(x);
			used.pb(0);
			ans++;          				
		} else if (t == 2) {
			while (ptr[x] < (int)lst[x].size()) {
				int j = lst[x][ptr[x]];
				if (!used[j])
					ans--;
				used[j] = 1;
				
				ptr[x]++;
			}
		} else {
			while (p < x) {
				if (!used[p])
					ans--;
				used[p] = 1;
				p++;
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}