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
const int MAXN = 100500;

int t, m, k, d, id[MAXN], bad, b[MAXN], minid, times[MAXN];
int a[MAXN], ans[MAXN];     
int main() {

	scanf("%d", &t);
	forn(tt, t) {
		scanf("%d%d", &m, &k);
		m--;
		forn(i, k) {
			scanf("%d", &a[i]);	
			ans[i] = 1;
			times[i] = 0;
		}
			
		forn(i, m) {
			scanf("%d%d", &id[i], &b[i]);
			id[i]--;
			if (id[i] != -1)
				times[id[i]]++;
		}
		
		d = 0;
		bad = 1;
		forn(i, m) {        			
			b[i] &= bad;
			
			if (b[i]) {
				bad = 0;
				
				minid = -1; 
				forn(j, k) {
					if (times[j] == 0) {
						if (minid == -1 || a[j] < a[minid])
							minid = j;
						if (a[j] <= d)
							ans[j] = 0;	
					}
				}
				
				d -= a[minid];
			}
			
			if (id[i] == -1)
				d++;
			else {
				times[id[i]]--;
				a[id[i]]--;
			}
		}
		
		forn(i, k)
			if (ans[i] && a[i] <= d)
				ans[i] = 0;

		forn(i, k)
			putchar(ans[i] ? 'N' : 'Y');
		cout << '\n';		
	}
	
	return 0;
}