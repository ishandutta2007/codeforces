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
const int MAXN = 100500 * 32;
        
int n;
int a[MAXN], pos[MAXN];
int root, sz;
int nxt[MAXN][2], par[MAXN], mark[MAXN], num[MAXN];
vi b;
set<pii> lib;

int main() {

	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);
		
	memset(nxt, -1, sizeof(nxt));
	memset(mark, 0, sizeof(mark));
	
	root = 0;
	num[root] = 1;
	par[root] = -1;
	
	sz = 1;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		b.clear();
		while (x > 0) {
			b.pb(x & 1);
			x >>= 1;	
		}
		
		b.pop_back();
		reverse(all(b));
		
		int v = root;
		int curNum = num[v];
		for (auto bit: b) {
			curNum = curNum * 2 + bit;
			if (nxt[v][bit] == -1) {
				nxt[v][bit] = sz;
				par[sz] = v;
				num[sz] = curNum;
				sz++;
			}
			v = nxt[v][bit];
		}
		
		mark[v] = 1;
		pos[i] = v;
	}
	
	forn(i, n)
		lib.insert({-a[i], i});
	
	while (true) {
		auto elem = *lib.begin();
		lib.erase(elem);
		
		int i = elem.Y;
		int x = a[i];
		//cerr << x << '\n';	
		
		int v = pos[i];
		while (v != -1 && mark[v]) {
			v = par[v];			
		}
		
		if (v == -1)
			break;	
		
		mark[v] = 1;
		mark[pos[i]] = 0;
		a[i] = num[v];
		pos[i] = v;
		
		lib.insert({-a[i], i});
	}
	
	sort(a, a + n);
	forn(i, n)
		printf("%d ", a[i]);
		
	return 0;
}