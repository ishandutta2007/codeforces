#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#define FILE_NAME "a"

bool cmp_s(const string &a, const string &b) {
	assert(!a.empty()); //!!!
	if (b.empty()) {
		return 1;
	}

	if (sz(a) != sz(b)) {
		return sz(a) < sz(b);
	}
	return a < b;
}

struct result {
	int mask;
	int type;
	string expr;
	
	result(int mask_, int type_, string expr_):
		mask(mask_), type(type_), expr(expr_) {}

	bool operator<(const result &r) const {
		return cmp_s(expr, r.expr);
	}
};

const int MAXN = 8;
const int MAXK = (1 << MAXN);
const int E = 0;
const int T = 1;
const int F = 2;

string res[MAXK][3];
vi vals_on_pos[MAXN];
set<result> results;
vector<result> processed;

void add_res(result r) {
	if (!res[r.mask][r.type].empty()) {
		results.erase(result(r.mask, r.type, res[r.mask][r.type]));
	}
	res[r.mask][r.type] = r.expr;
	results.insert(r);
}

void add_res(int mask, int type, string expr) {
	add_res(result(mask, type, expr));
}

void relax(result nres) {
	if (cmp_s(nres.expr, res[nres.mask][nres.type])) {
		add_res(nres);
	}
}

void gen_state(int id) {
	vi t(3, 0);
	t[id] = 1;

	int mask = 0;
	forn(pos, MAXN) {
		int val = vals_on_pos[pos][id];
		mask |= (val << pos);
	}

	string str;
	str += ('x' + id);
	add_res(mask, F, str);
}

void combine(result l, result r) {
	if ((l.type == E && r.type == T) || (l.type == T && r.type == E)) {
		result nres(l.mask | r.mask, E, res[l.mask][l.type] + "|" + res[r.mask][r.type]);
		relax(nres);
	}

	if ((l.type == T && r.type == F) || (l.type == F && r.type == T)) {
		result nres(l.mask & r.mask, T, res[l.mask][l.type] + "&" + res[r.mask][r.type]);
		relax(nres);
	}
}

void bfs() {
	while (!results.empty()) {
		result cur = *results.begin();
		results.erase(cur);

		int mask = cur.mask;
		int type = cur.type;

		//cout << "look " << mask << ' ' << type << ' ' << res[mask][type] << endl;
		// single moves
		if (type == E) {
			result nres(mask, F, "(" + res[mask][type] + ")");
			relax(nres);
		}
		if (type == T) {
			result nres(mask, E, res[mask][type]);
			relax(nres);
		}
		if (type == F) {
			result nres(mask, T, res[mask][type]);
			relax(nres);
		}
		if (type == F) {
			result nres((MAXK - 1) ^ mask, F, "!" + res[mask][type]);
			relax(nres);
		}

		// multi moves
		for (auto lop: processed) {
			combine(lop, cur);
		}
		for (auto rop: processed) {
			combine(cur, rop);
		}
		
		processed.pb(cur);
	}
}

void precalc() {
	forn(pos, MAXN) {
		vals_on_pos[pos].clear();
		vals_on_pos[pos].resize(3, 0);

		vals_on_pos[pos][0] = (pos / 4) % 2;
		vals_on_pos[pos][1] = (pos / 2) % 2;
		vals_on_pos[pos][2] = (pos / 1) % 2;
	}

	// gen starts

	forn(id, 3) {
		gen_state(id);
	}

	processed.clear();

	bfs();
}

string s;

bool read() {
	if (!(cin >> s)) {
		return 0;
	}
	return 1;
}

string solve() {
	int mask = 0;
	forn(i, MAXN) {
		mask |= (s[i] - '0') << i;
	}

	string ans = res[mask][0];
	forn(i, 3) {
		if (cmp_s(res[mask][i], ans)) {
			ans = res[mask][i];
		}
	}

	return ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
    //freopen(FILE_NAME ".out", "w", stdout);
#endif

    precalc();
/*
	string c;
    c.pb('x');
    c.pb('y');
    c.pb('z');
    c.pb('(');
    c.pb(')');
    c.pb('|');
    c.pb('&');
    c.pb('!');
    sort(all(c));
    cout << c << endl;
    cout << "---" << endl;

    forn(mask, MAXK) {
    	forn(t, 3) {
    		printf("% 4d %d ", mask, t);
    		cout << res[mask][t] << endl;
    	}
    }
*/
    int TT;
    cin >> TT;
    forn(t, TT) {
    	assert(read());
    	cout << solve() << '\n';
    }

    return 0;
}