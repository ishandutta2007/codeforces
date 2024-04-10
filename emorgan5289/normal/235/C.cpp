#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct automaton {

    struct node {
        ll p, len, clo; // clo indicates whether a state was created by cloning
        map<ll, ll> adj; // transitions of form {char, destination}
    };

    ll n = 1, l = 0;
    vector<node> a;

    // append character c to the automaton,
    // runs in O(log(min(n, K))) amortized, where K is the alphabet size.
    void append(ll c) {
        a.push_back({0, a[l].len+1, 0, {}});
        ll r = n++, x = l, y; l = r;
        for (; x != -1 && !a[x].adj.count(c); x = a[x].p)
            a[x].adj[c] = r;
        if (x == -1) a[r].p = 0;
        else if (a[y = a[x].adj[c]].len == a[x].len+1)
            a[r].p = y;
        else {
            a.push_back({a[y].p, a[x].len+1, 1, a[y].adj});
            a[r].p = a[y].p = n++;
            for (; x != -1 && a[x].adj[c] == y; x = a[x].p)
                a[x].adj[c] = n-1;
        }
    }

    automaton() { a.push_back({-1, 0, 0, {}}); }

    template<typename it>
    automaton(it first, it last) : automaton() {
        for (it i = first; i != last; i++) append(*i);
    }

    automaton(string str) : automaton(str.begin(), str.end()) {}

    // let x be the state corresponding to string s, then this returns
    // the state corresponding to s + character c (possibly -1).
    // runs in O(log(min(n, K))) time.
    ll push(ll x, ll c) {
        if (a[x].adj.count(c)) return a[x].adj[c];
        else return -1;
    }

    // let x > 0 be the state corresponding to string s with length len, then
    // this returns the state corresponding to s with its first char removed.
    // runs in O(1) time.
    ll pop(ll x, ll len) {
        if (len == a[a[x].p].len+1) return a[x].p;
        return x;
    }

    // returns the index of the state corresponding to the input,
    // or -1 if the input is not present as a substring.
    // runs in O(m), where m is the length of the input.
    template<typename it>
    ll find(it first, it last) {
        ll x = 0;
        for (it i = first; i != last; i++)
            if((x = push(x, *i)) == -1) return -1;
        return x;
    }

    ll find(string str) { return find(str.begin(), str.end()); }

    // returns the indices of all states sorted by len, which is a
    // topological ordering of both the transition graph and the reversed link tree.
    // runs in O(n).
    vector<ll> order() const {
        vector<ll> out;
        queue<ll> q; q.push(0);
        while (!q.empty()) {
            ll i = q.front(); q.pop(), out.push_back(i);
            for (auto& [c, j] : a[i].adj)
                if (a[j].len == a[i].len+1) q.push(j);
        }
        return out;
    }

    vector<ll> sz;

    // computes the sz array, runs in O(n). sz[i] = |endpos(i)|.
    void refresh_sz() {
        sz.assign(n, 0);
        auto o = order();
        for (ll i = n-1; i > 0; i--) {
            if (!a[o[i]].clo) sz[o[i]]++;
            sz[a[o[i]].p] += sz[o[i]];
        }
        sz[0] = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    automaton a(s);
    a.refresh_sz();
    ll n; cin >> n;
    while (n--) {
        set<ll> v;
        string t; cin >> t;
        ll m = t.size(), x = 0, y, i = 0;
        t += t; ll out = 0;
        for (ll k = m; k < 2*m; k++) {
            while (i < k && (y = a.push(x, t[i])) != -1)
                x = y, i++;
            if (i == k && !v.count(x))
                out += a.sz[x], v.insert(x);
            if (x > 0) x = a.pop(x, i-k+m);
        }
        cout << out << "\n";
    }
}