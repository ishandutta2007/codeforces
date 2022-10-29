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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1111;

int n, ans;
int a[MAXN];
map<int, int> f;
int L[MAXN][MAXN], R[MAXN][MAXN];
int prv[MAXN][MAXN];
int T, cur;
int add[MAXN], used[MAXN];

int main() {

	cin >> n;
	forn(i, n) {
		cin >> a[i];
		f[a[i]]++;
	}
	
	ans = 2;
	n = 0;
	
	for (auto p: f) {
		int k = p.X;
		int t = p.Y;
		
		if (k == 0) {
			ans = max(ans, t);
			t = min(t, 1);	
		} else
			t = min(t, 4);
			
		forn(i, t) 
			a[n++] = k;			
	}
	
	//forn(i, n)
	//	cout << a[i] << " \n"[i == n - 1];
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j) {
				L[i][j] = -1;
				int x = lower_bound(a, a + n, a[i] + a[j]) - a;
				if (x != n && a[x] == a[i] + a[j]) {
					while (x > 0 && a[x] == a[x - 1])
						x--;

					L[i][j] = R[i][j] = x;	
					while (x < n) {
						R[i][j] = x;
						if (x < n - 1 && a[x] == a[x + 1])
							x++;
						else
							break;
					}
				}
			}
	
	T = 1;
	int f1, f2;
	bool ok;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != j) {
				cur = 2;
				
				f1 = i;
				f2 = j;
				
				T++;
				used[f1] = T;		
				used[f2] = T;
				
				while (true) {
					if (L[f1][f2] == -1)
						break;
						
					ok = 0;		
					for (int k = L[f1][f2]; k <= R[f1][f2]; k++)
						if (used[k] != T) {
							ok = 1;
							f1 = f2;
							f2 = k;
							cur++;
							used[k] = T;
							break;
						}
						
					if (!ok)
						break;
				}
				
				ans = max(ans, cur);
			}
		}
		
	cout << ans << '\n';
	
    return 0;
}