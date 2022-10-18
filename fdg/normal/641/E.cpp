#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y0 smthngy0
#define y1 smthngy1
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define str fuck2
#define ld long double
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

typedef vector < int > vi;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int N = 4e6 + 10;
const int INF = 1000000000; //1e9
const int inf = 2e9+1;
const double eps = 1e-9;

struct query{
	int type, t, val;
	void read() {
		scanf("%d%d%d", &type, &t, &val);
	}
};
vi f[N];
int n;
vi d[N];
query q[N];
void add(int t, int x, int d) {
	while (x < sz(f[t])) {
		f[t][x] += d;
		x |= (x + 1);
	}
}
int get(int t, int x) {
	int ret = 0;
	while (x >= 0) {
		ret += f[t][x];
		x &= (x + 1); x--;
	}
	return ret;
}
int main(){
	//FREIN("input.txt");
	scanf("%d", &n);
	vi h;
	REP(i, n) {
		q[i].read();
		h.pb(q[i].val);
	}
	sort(h.begin(), h.end());
	REP(i, n) {
		int x = q[i].val;
		int left = 0, right = sz(h);
		while (left + 1 < right) {
			int middle = (left + right) >> 1;
			if (h[middle] > x) right = middle;
				else left = middle;
		}
		q[i].val = left;
		d[left].pb(q[i].t);
	}
	REP(i, 1000000) {
		if (sz(d[i]) == 0) continue;
		sort(d[i].begin(), d[i].end());
	}
	REP(i, n) {
		int x = q[i].t;
		int j = q[i].val;
		int left = 0, right = sz(d[j]);
		while (left + 1 < right) {
			int m = (left + right) >> 1;
			if (d[j][m] > x) 
				right = m;
			else
				left = m;
		}
		q[i].t = left;
	}
	REP(i, 1000000) {
		if (!sz(d[i]))continue;
		f[i].resize(sz(d[i]));
	}
	REP(i, n) {
		if (q[i].type == 1) {
			add(q[i].val, q[i].t, 1);
		} else if (q[i].type == 2) {
			add(q[i].val, q[i].t, -1);
		} else {
			printf("%d\n", get(q[i].val, q[i].t));
		}
	}
	return 0;
}