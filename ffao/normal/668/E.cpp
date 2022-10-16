#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
#endif

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

vector<pair<int,int>> condsA;
vector<pair<int,int>> condsB;
bitset<2100> g1[2100];
bitset<2100> g2[2100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    auto conv = [](int a) {return a >= 0 ? (a-1) : (~(-a-1));};
    auto conv2 = [](int a) {return a >= 0 ? (2*(a-1)) : (2*(-a)-1);};
    auto conv3 = [](int a) {
        int idx = a/2;
        if (a & 1) idx = ~idx;
        return idx;
    };

    TwoSat A(n), B(n);

    for (int i = 0; i < m1; i++) {
        int a, b; cin >> a >> b;
        g1[conv2(a)^1][conv2(b)] = 1;
        g1[conv2(b)^1][conv2(a)] = 1;
        a = conv(a), b = conv(b);
        condsA.push_back({a,b});
        A.either(a,b);
    }

    for (int i = 0; i < m2; i++) {
        int a, b; cin >> a >> b;
        g2[conv2(a)^1][conv2(b)] = 1;
        g2[conv2(b)^1][conv2(a)] = 1;
        a = conv(a), b = conv(b);
        condsB.push_back({a,b});
        B.either(a,b);
    }

    bool hA = A.solve(), hB = B.solve();

    if (!hA && !hB) {
        cout << "SIMILAR" << endl;
        return 0;
    }
    if (hA && !hB) {
        for (int i = 0; i < n; i++) cout << A.values[i] << " ";
        cout << endl;
        return 0;
    }
    if (!hA && hB) {
        for (int i = 0; i < n; i++) cout << B.values[i] << " ";
        cout << endl;
        return 0;
    }

    for (int k = 0; k < 2*n; k++) {
        for (int i = 0; i < 2*n; i++) if (g1[i][k]) {
            g1[i] |= g1[k];
        }
        for (int i = 0; i < 2*n; i++) if (g2[i][k]) {
            g2[i] |= g2[k];
        }
    }

    vi fixed(n);

    for (int i = 0; i < 2*n; i++) {
        int j = i ^ 1;
        
        if (g1[i][j] && !g2[i][j]) {
            TwoSat C(n);
            for (auto p : condsB) {
                C.either(p.first, p.second);
            }

            C.either(conv3(j^1), conv3(j^1));
            C.either(conv3(i), conv3(i));
            C.solve();

            for (int i = 0; i < n; i++) cout << C.values[i] << " ";
            cout << endl;
            return 0;
        }
        if (!g1[i][j] && g2[i][j]) {
            TwoSat C(n);
            for (auto p : condsA) {
                C.either(p.first, p.second);
            }

            C.either(conv3(j^1), conv3(j^1));
            C.either(conv3(i), conv3(i));
            C.solve();

            for (int i = 0; i < n; i++) cout << C.values[i] << " ";
            cout << endl;
            return 0;
        }
        if (g1[i][j]) fixed[i/2] = 1;
    }

    for (int i = 0; i < 2*n; i++) if (!fixed[i/2]) {
        for (int j = 0; j < 2*n; j++) if (!fixed[j/2] && j != i) {
            if (g1[i][j] && !g2[i][j]) {
                TwoSat C(n);
                for (auto p : condsB) {
                    C.either(p.first, p.second);
                }

                C.either(conv3(j^1), conv3(j^1));
                C.either(conv3(i), conv3(i));
                C.solve();

                for (int i = 0; i < n; i++) cout << C.values[i] << " ";
                cout << endl;
                return 0;
            }
            if (!g1[i][j] && g2[i][j]) {
                TwoSat C(n);
                for (auto p : condsA) {
                    C.either(p.first, p.second);
                }

                C.either(conv3(j^1), conv3(j^1));
                C.either(conv3(i), conv3(i));
                C.solve();

                for (int i = 0; i < n; i++) cout << C.values[i] << " ";
                cout << endl;
                return 0;
            }
        }
    }

    cout << "SIMILAR" << endl;
    return 0;
}