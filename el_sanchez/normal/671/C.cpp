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
const int MAXN = 200500;
const int MAXK = 262144;
    
struct vertex {
	ll sum, upd;
	ll mn, mx;
	bool flag;

	vertex() {
		sum = upd = flag = 0;
		mn = mx = 0;
	}
};

vertex t[2 * MAXK + 3];

int n;

void build(int *a) {
	for (int i = 0; i < n; i++) {
		t[MAXK + i].sum = a[i];
		t[MAXK + i].mn = t[MAXK + i].mx = a[i];
	}

	for (int v = MAXK - 1; v >= 1; v--) {
		t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;		
		t[v].mx = max(t[2 * v].mx, t[2 * v + 1].mx);
		t[v].mn = min(t[2 * v].mn, t[2 * v + 1].mn);
	}
}

void push(int v, int L, int R) {
	if (t[v].flag) {
		if (L + 1 < R) {
			t[v * 2].sum = 1ll * t[v].upd * (R - L) / 2;
			t[v * 2 + 1].sum = 1ll * t[v].upd * (R - L) / 2;
			t[v * 2].upd = t[v].upd;
			t[v * 2 + 1].upd = t[v].upd;
			t[v * 2].mx = t[v * 2].mn = t[v * 2 + 1].mx = t[v * 2 + 1].mn = t[v].upd;
			t[v * 2].flag = t[v * 2 + 1].flag = 1;			
		}
		
		t[v].upd = 0;
		t[v].flag = 0;
	}
}

ll get(int v, int L, int R, int lx, int rx) {
	push(v, L, R);

	if (rx <= L || R <= lx)
		return 0;
	if (lx <= L && R <= rx)
		return t[v].sum;

	return get(v * 2, L, (L + R) >> 1, lx, rx) + get(v * 2 + 1, (L + R) >> 1, R, lx, rx);	
}

void upd(int v, int L, int R, int lx, int rx, ll val) {
	push(v, L, R);

	if (rx <= L || R <= lx || t[v].mn >= val)
		return;
	if (lx <= L && R <= rx && t[v].mx <= val) {
		t[v].sum = 1ll * val * (R - L);
		t[v].upd = val;
		t[v].flag = 1;
		t[v].mx = t[v].mn = val;
		return;	
	}
		
	upd(v * 2, L, (L + R) >> 1, lx, rx, val);
	upd(v * 2 + 1, (L + R) >> 1, R, lx, rx, val);
	
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
	t[v].mx = max(t[2 * v].mx, t[2 * v + 1].mx);
	t[v].mn = min(t[2 * v].mn, t[2 * v + 1].mn);	
}

ll get(int L, int R) {
	return get(1, 1, MAXK + 1, L + 1, R + 2);	
}

void upd(int L, int R, ll x) {
	upd(1, 1, MAXK + 1, L + 1, R + 2, x);	
}
        
int a[MAXN], b[MAXN];
ll num[MAXN];
ll ans;
vi divs[MAXN];
vi cd[2];

int main() {
	
	scanf("%d", &n);
	
	if (n <= 2) {
		cout << 0 << '\n';
		return 0;
	}
	
	forn(i, n)
		scanf("%d", &a[i]);

	forn(i, n) {
		int x = a[i];
		
		cd[0].clear();
		cd[1].clear();
		for (int d = 1; d * d <= x; d++) {
			if (x % d == 0) {
				cd[0].pb(d);
				cd[1].pb(x / d);
				//cout << d << ' ' << x / d << '\n';
			}
		}
		
		ford(j, cd[1].size())
			cd[0].pb(cd[1][j]);
		cd[0].resize(unique(all(cd[0])) - cd[0].begin());
		
		for (auto d: cd[0])
			divs[d].pb(i);
	}
	
	forn(i, n)
		b[i] = i;	
	build(b);	

	int C = MAXN - 2;
	
	num[C] = 1ll * n * (n + 1) / 2;
	for (int i = C; i >= 2; i--) {
		if (divs[i].size() >= 2) {
			int sz = divs[i].size();
			
			int i1 = divs[i][0];
			int i2 = divs[i][1];
			
			int ix = divs[i][sz - 2];
			int iy = divs[i][sz - 1];
			
			upd(i2 + 1, n - 1, n);
			upd(i1 + 1, i2, iy);
			upd(0, i1, ix);
		}
		/*
		cout << i - 1 << ":\n";
		forn(j, n)
			cout << get(j, j) << ' ';
		cout << '\n';
		*/
		num[i - 1] = 1ll * n * n - get(0, n - 1);
	}
	/*
	forn(i, 10) {
		cout << i << ":";
		for (auto j: divs[i])
			cout << ' ' << j;
		cout << '\n';	
	}
	*/
		
	ans = 0;
	for (int i = 1; i <= C; i++) {
		//cout << "num " << i << ": " << num[i] - num[i - 1] << '\n';
		ans += 1ll * i * (num[i] - num[i - 1]);
	}
	/*
	ans -= a[0];
	if (n > 1)
		ans -= a[n - 1];
	*/
	cout << ans - 3 << '\n';
	
	return 0;
}