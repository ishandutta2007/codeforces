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
const ll LINF = 1E18;
const int MAXN = 200500;
const int MAXK = 262144;

struct node {
	ll minVal;
	ll oddF, evenF, altSum, upd;
	bool flag;

	node() {
		minVal = oddF = evenF = LINF;
		altSum = 0;
		upd = flag = 0;
	}
};

int n, q;
int a[MAXN];
node t[2 * MAXK + 3];

void recalc(int v, int L, int R) {
	if (L + 2 == R) {
		t[v].altSum = t[2 * v + 1].altSum - t[2 * v].altSum;
		t[v].evenF = t[2 * v].evenF;
		t[v].oddF = t[2 * v + 1].evenF - t[2 * v].evenF;
		t[v].minVal = min(t[2 * v].minVal, t[2 * v + 1].minVal);
		return;		
	}

	t[v].altSum = t[2 * v + 1].altSum + t[2 * v].altSum;
	t[v].evenF = min(t[2 * v].evenF, t[2 * v + 1].evenF - t[2 * v].altSum);
	t[v].oddF = min(t[2 * v].oddF, t[2 * v + 1].oddF + t[2 * v].altSum);
	t[v].minVal = min(t[2 * v].minVal, t[2 * v + 1].minVal);	
}

void addLocal(int v, int L, int R, int k) {
	t[v].flag = 1;
	t[v].upd += k;
	t[v].minVal += k;

	t[v].evenF += k;
	if (L + 1 == R) {		
		t[v].altSum += k;
	}	
}

void push(int v, int L, int R) {
	if (t[v].flag) {
		if (L + 1 < R) {
			int M = (L + R) >> 1;
			addLocal(v * 2, L, M, t[v].upd);
			addLocal(v * 2 + 1, M, R, t[v].upd);
		}
	 	t[v].flag = 0;
	 	t[v].upd = 0;
	}
}

void add(int v, int L, int R, int lx, int rx, int k) {
	push(v, L, R);
	if (R <= lx || rx <= L)
		return;
	if (lx <= L && R <= rx) {
		addLocal(v, L, R, k);
		return;       			
	}
	
	int M = (L + R) >> 1;
	add(v * 2, L, M, lx, rx, k);
	add(v * 2 + 1, M, R, lx, rx, k);
	recalc(v, L, R);	
}

void add(int L, int R, int k) {
	add(1, 1, MAXK + 1, L + 1, R + 2, k);	
}

//bool lastOdd;
int gL;
ll glob;

pair<ll, ll> fmin(pair<ll, ll> a, pair<ll, ll> b) {
//	cerr << "!\n";
	return {min(a.X, b.X), min(a.Y, b.Y)};	
}

pair<ll, ll> get(int v, int L, int R, int lx, int rx) {
	push(v, L, R);
	
	pair<ll, ll> ans = {LINF, LINF};
	if (R <= lx || rx <= L)
		return ans;
		
	if (lx <= L && R <= rx) {
		ans.X = min(ans.X, t[v].minVal);
		//if (!lastOdd)
		//	glob *= -1;
			
		int evenDec = (L & 1) == (gL & 1) ? -1 : 0;
		int oddDec = (L & 1) != (gL & 1) ? -1 : 0;
		
		if (L + 1 == R) {
			ans.Y = min(ans.Y, t[v].evenF - glob + evenDec);
			glob = t[v].altSum - glob;
		} else {
			ans.Y = min(ans.Y, t[v].evenF - glob + evenDec);
			ans.Y = min(ans.Y, t[v].oddF + glob + oddDec);
			glob = t[v].altSum + glob;
		}
		
		//lastOdd = (R & 1);
		//cout << L << ".." << R << '\n';
		//cout << "NEW GLOB: " << glob << '\n';
		return ans;
	}
	
	int M = (L + R) >> 1;
	ans = fmin(ans, get(v * 2, L, M, lx, rx));
	ans = fmin(ans, get(v * 2 + 1, M, R, lx, rx));
	return ans;
}

pair<ll, ll> get(int L, int R) {
	return get(1, 1, MAXK + 1, L + 1, R + 2);	
}

void rec(int v, int L, int R) {
	if (L + 1 == R)
		return;
	int M = (L + R) >> 1;
	rec(v * 2, L, M);
	rec(v * 2 + 1, M, R);
	recalc(v, L, R);	
}

void build() {
	for (int i = 0; i < n; i++) {
		int v = MAXK + i;
		t[v].minVal = t[v].evenF = t[v].altSum = a[i];
		t[v].oddF = LINF;		
	}
	
	rec(1, 1, MAXK + 1);
}

int main() {
	
	cin >> n;
	forn(i, n)
		scanf("%d", &a[i]);

	build();
	cin >> q;
	forn(i, q) {
		int t, L, R, k;
		scanf("%d%d%d", &t, &L, &R);
		if (t == 1) {
			scanf("%d", &k);
			add(L, R, k); 	
		} else {
			//lastOdd = !(L & 1);
			gL = L + 1;
			glob = 0;
			pair<ll, ll> f = get(L, R);
			ll minVal = f.X;
			ll minAltSum = f.Y;
			
			if ((L & 1) == (R & 1))
				glob--;
			//cout << minVal << ' ' << minAltSum << ' ' << glob << '\n';
			bool ans;
			
			if (minVal <= 0) {
				ans = 0;
			} else {
				if (minAltSum < 0 || glob != 0)
					ans = 0;
				else
					ans = 1;
			}
			
			printf("%d\n", ans);
		}
	}
	return 0;
}