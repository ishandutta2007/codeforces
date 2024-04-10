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

struct state {
    int len, link;
    int next[4];
    long long mn[4];
};

const int MAXLEN = 100010;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next[c]) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[clone].next));
            // st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

const ll INF = 1000000000000000100LL;

int seen[410000];

void dfs(int v) {
    if (seen[v]) return;
    seen[v]=1;

    // dbg(v);
    for (int i = 0; i < 4; i++) st[v].mn[i] = INF;

    for (int i = 0; i < 4; i++) {
        if (!st[v].next[i]) {
            st[v].mn[i] = 0;
            continue;
        }

        int x = st[v].next[i];
        dfs(x);
        for (int i = 0; i < 4; i++) st[v].mn[i] = min(st[v].mn[i], st[x].mn[i] + 1);
    }
}

ll g[100][4][4];
ll cur[4][4];
ll nw[4][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sa_init();

    ll n;
    string t;
    cin >> n >> t;
    for (char c : t) sa_extend(c-'A');
    // dbg('hi');
    dfs(0);
    // dbg('done');

    for (int k = 0; k < 60; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) g[k][i][j] = INF;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            g[0][i][j] = st[st[0].next[i]].mn[j] + 1;
        }
    }

    for (int k = 1; k < 60; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int m = 0; m < 4; m++) {
                    g[k][i][j] = min(g[k][i][j], g[k-1][i][m] + g[k-1][m][j]);
                }
            }
        }
    }

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << g[59][i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    ll ans = 0;
    for (int k = 59; k >= 0; k--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                nw[i][j] = INF;
                for (int m = 0; m < 4; m++) {
                    nw[i][j] = min(nw[i][j], cur[i][m] + g[k][m][j]);
                }
                // if (k==0) {
                //     dbg(i,j,cur[i][0],g[k][0][j],nw[i][j]);
                // }
            }
        }

        bool ok = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (nw[i][j] <= n) ok = true;
            }
        }

        if (ok) {
            ans += (1LL<<k);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) cur[i][j] = nw[i][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (cur[i][j] < n) {
                ans++;
                goto fim;
            }
        }
    }

fim:
    cout << ans << endl;
    return 0;
}