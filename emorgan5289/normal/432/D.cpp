#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct automaton {

    struct node {
        int link; // suffix link
        int len; // stores the length of the longest suffix for this state
        bool clo; // indicates whether a state was created by cloning.
        int fp; // stores the smallest element of endpos.
        map<int, int> adj; // transitions of form {char, destination}
    };

    // state 0 = empty string
    // state -1 = string which does not exist in the text

    int n = 1, l = 0;
    vector<node> a;

    // append character c to the automaton,
    // runs in O(log(min(n, K))) amortized, where K is the alphabet size.
    void append(int c) {
        a.push_back({0, a[l].len+1, 0, a[l].len, {}});
        int r = n++, x = l, y; l = r;
        for (; x != -1 && !a[x].adj.count(c); x = a[x].link)
            a[x].adj[c] = r;
        if (x == -1) a[r].link = 0;
        else if (a[y = a[x].adj[c]].len == a[x].len+1)
            a[r].link = y;
        else {
            a.push_back({a[y].link, a[x].len+1, 1, a[y].fp, a[y].adj});
            a[r].link = a[y].link = n++;
            for (; x != -1 && a[x].adj[c] == y; x = a[x].link)
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
    int push(int x, int c) {
        return x != -1 && a[x].adj.count(c) ? a[x].adj[c] : -1;
    }

    // let x > 0 be the state corresponding to string s with length len, then
    // this returns the state corresponding to s with its first char removed.
    // runs in O(1) time.
    int pop(int x, int len) {
        return len == a[a[x].link].len+1 ? a[x].link : x;
    }

    // returns the state corresponding to the input,
    // or -1 if the input is not present as a substring.
    // runs in O(input).
    template<typename it>
    int find(it first, it last) {
        int x = 0;
        for (it i = first; i != last && x != -1; i++)
            x = push(x, *i);
        return x;
    }

    int find(string str) { return find(str.begin(), str.end()); }

    // returns the indices of all states sorted by len, which is a
    // topological ordering of both the transition graph and the reversed link tree.
    // runs in O(n).
    vector<int> order() const {
        vector<int> out;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int i = q.front(); q.pop(), out.push_back(i);
            for (auto& [c, j] : a[i].adj)
                if (a[j].len == a[i].len+1) q.push(j);
        }
        return out;
    }

    vector<int> sz;

    // computes the sz array, runs in O(n). sz[i] = |endpos(i)|.
    void refresh_sz() {
        sz.assign(n, 0);
        auto o = order();
        for (int i = n-1; i > 0; i--) {
            if (!a[o[i]].clo) sz[o[i]]++;
            sz[a[o[i]].link] += sz[o[i]];
        }
        sz[0] = 0;
    }
};

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    automaton a(s);
    a.refresh_sz();
    int x = 0, len = 0;
    auto z = z_function(s);
    vector<array<int, 2>> ans;
    for (char c : s) {
        x = a.push(x, c);
        len++;
        if (len == z.size() || z[s.size()-len] >= len)
            ans.pb({len, a.sz[x]});
    }
    cout << ans.size() << "\n";
    for (auto& [p, q] : ans) cout << p << " " << q << "\n";
}