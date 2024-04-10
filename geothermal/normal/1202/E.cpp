#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle

const int MOD = 805306457;
const ll INF = 1e18;
const int MX = 200001; //check the limits, dummy


ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    return modExp(base, MOD-2);
}

ll mul(ll A, ll B) {
    return (A*B)%MOD;
}

ll add(ll A, ll B) {
    return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

struct AhoCorasick {
    static const int K = 26;

    struct Vertex {
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        ll value = -1;
        ll num = 0;

        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };

    vector<Vertex> t;

    void init() {
        Vertex v; t.pb(v);
    }



    void add_string(string const& s, int count) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        t[v].num = count;
    }

    ll dfs(int v) {
        if (t[v].value != -1) {
            return t[v].value;
        }
        ll ans = t[v].num;
        ans += dfs(get_link(v)); // is this right?
        return t[v].value = ans;
    }

    void compute() {
        t[0].value = 0;
        FOR(i, 1, sz(t)) {
            dfs(i);
        }
    }

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string T; cin >> T;

    int N; cin >> N;
    map<string, int> strings;
    F0R(i, N) {
        string cur; cin >> cur;
        if (strings.count(cur)) {
            strings[cur]++;
        } else {
            strings.insert(mp(cur, 1));
        }
    }

    vector<pair<string, int> > strData;
    for (auto it = strings.begin(); it != strings.end(); it++) {
        strData.pb(*it);
    }

    AhoCorasick start; start.init();
    F0R(i, sz(strData)) {
        start.add_string(strData[i].f, strData[i].s);
    }
    start.compute();
    int cur = 0;
    ll countEnd[sz(T)], countStart[sz(T)];
    F0R(i, sz(T)) {
        cur = start.go(cur, T[i]);
        countEnd[i] = start.t[cur].value;
    }

    F0R(i, sz(strData)) {
        reverse(all(strData[i].f));
    }

    reverse(all(T));

    AhoCorasick end; end.init();
    F0R(i, sz(strData)) {
        end.add_string(strData[i].f, strData[i].s);
    }
    end.compute();
    cur = 0;
    F0R(i, sz(T)) {
        cur = end.go(cur, T[i]);
        countStart[sz(T)-1-i] = end.t[cur].value;
    }

    /*F0R(i, sz(T)) {
        cout << countStart[i] << " ";
    }
    cout << endl;*/


    ll ans = 0;
    F0R(i, sz(T) - 1) {
        ans += countEnd[i] * countStart[i+1];
    }

    cout << ans << endl;



    /*ll hsh1 = 402653189, hsh2 = 805306457;
    ll hashT = 0;
    int X = sz(T);
    ll preHshT[X], sufHshT[X];
    F0R(i, sz(T)) {
        hashT *= hsh1; hashT %= hsh2;
        hashT += T[i] - 'a';
        hashT %= hsh2;
        preHshT[i] = hashT;
    }

    hashT = 0;
    F0Rd(i, sz(T)) {
        hashT *= hsh1; hashT %= hsh2;
        hashT += T[i] - 'a';
        hashT %= hsh2;
        sufHshT[X-i-1] = hashT;
    }

    int N; cin >> N;
    ll countPre[X-1], countSuf[X-1];
    F0R(i, X-1) {
        countPre[i] = 0; countSuf[i] = 0;
    }

    ll exponent = modExp(hsh1, X);
    map<pl, ll> data;
    F0R(curString, N) {
        string S; cin >> S;
        ll hash = 0;
        int Y = sz(S);
        F0R(i, Y) {
            hash *= hsh1; hash %= hsh2;
            hash += S[i] - 'a';
            hash %= hsh2;
            if (i < X-1 && hash == preHshT[i]) {
                countPre[i]++;
            }
        }

        if (!data.count(hash)) {
            map<ll, ll> blank; data.insert(mp(hash, blank));
        }

        if (!data[hash].count(Y)) {
            data[hash].insert(mp(Y, 0));
        }
        data[hash][Y]++;


        hash = 0;
        F0Rd(i, Y) {
            hash *= hsh1; hash %= hsh2;
            hash += S[i] - 'a';
            hash %= hsh2;
            if (Y - i -1 < X-1 && hash == sufHshT[Y-i-1]) {
                countSuf[Y-i-1]++;
            }
        }

        hash = 0;
        F0R(i, Y) {
            hash *= hsh1; hash %= hsh2;
            hash += S[i] - 'a';
            hash %= hsh2;
            if (i >= X) hash = sub(hash, exponent * (S[i-X] - 'a'));
            if (hash == hashT) ans+=N;
        }
    }

    ll ans = 0;
    F0R(i, X) {

    }

    F0R(i, X-1) {
        ans += countPre[i] * countSuf[X-2-i];
    }

    cout << ans << endl;*/


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE