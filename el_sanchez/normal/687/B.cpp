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
const int MAXN = 1000500;

int n, k;
int a[MAXN];
int cnt, d[MAXN], pw[MAXN], maxpw[MAXN];

int main() {
	
	scanf("%d%d", &n, &k);
	
	int K = k;
	for (int i = 2; i * i <= K; i++)
		if (K % i == 0) {
			d[cnt] = i;
			pw[cnt] = 0;
			while (K % i == 0) {
				K /= i;
				pw[cnt]++;
			}
			cnt++;	
		}
	if (K > 1) {
		d[cnt] = K;
		pw[cnt] = 1;
		cnt++;	
	}
		
	forn(i, cnt)
		maxpw[i] = 0;
		
	int curpw = 0;
	forn(i, n) {
		scanf("%d", &a[i]);
		forn(j, cnt) {
			curpw = 0;
			while (a[i] % d[j] == 0) {
				a[i] /= d[j];
				curpw++;
			}
			maxpw[j] = max(maxpw[j], curpw);
		}
	}
	
	forn(i, cnt)
		if (pw[i] > maxpw[i]) {
			cout << "No\n";
			return 0;
		}
		
	cout << "Yes\n";

		
	
	return 0;
}