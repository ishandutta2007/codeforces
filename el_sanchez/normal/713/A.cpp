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
const int LEN = 21;
const int MAXN = 42 * 100500;

int n;
int root = 0, sz = 1;
int nxt[MAXN][2], sum[MAXN];
char q;
ll x;

int main() {
	
	memset(nxt, -1, sizeof(nxt));
	memset(sum, 0, sizeof(sum));
	
	scanf("%d\n", &n);
	forn(i, n) {
		scanf("%c %I64d\n", &q, &x);
		
		//cout << s << '\n';
		int v = root;	
		forn(j, LEN) {
			int e = (x & 1);
			if (nxt[v][e] == -1) {
				nxt[v][e] = sz;
				sz++;
			}
			v = nxt[v][e];
			x /= 10;		
		}
		
		if (q == '+' || q == '-') {
			sum[v] += (q == '+' ? 1 : -1);
		} else {
			printf("%d\n", sum[v]);
		}
	}
	
	return 0;
}