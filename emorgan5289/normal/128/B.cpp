#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct automaton {

    int n = 1, l = 0;
    int p[2*N], len[2*N];
    map<int, int> adj[2*N]; // transitions of form {char, destination}
    bool clo[2*N]; // indicates whether a state was created by cloning
    int sz[2*N]; // sz[i] = |endpos(i)|

    automaton() { p[0] = -1, len[0] = 0; }

    // returns the number of vertices in the automaton.
    int size() { return n; }

    // append character c to the string,
    // runs in O(log(min(n, K))) amortized, where K is the alphabet size.
    void append(int c) {
        int r = n++, x = l, y, z;
        len[r] = len[l]+1, clo[r] = 0, l = r;
        for (; x != -1 && !adj[x].count(c); x = p[x])
            adj[x][c] = r;
        if (x == -1) p[r] = 0;
        else if (len[y = adj[x][c]] == len[x]+1)
            p[r] = y;
        else {
            len[z = n++] = len[x]+1, adj[z] = adj[y];
            p[z] = p[y], p[r] = p[y] = z, clo[z] = 1;
            for (; x != -1 && adj[x][c] == y; x = p[x])
                adj[x][c] = z;
        }
    }

    // returns the index of the state corresponding to the input,
    // or -1 if the input is not present as a substring.
    // runs in O(m), where m is the length of the input.
    template<typename it>
    int get(it first, it last) {
        int x = 0;
        for (it i = first; i != last; i++) {
            if (adj[x].count(*i)) x = adj[x][*i];
            else return -1;
        }
        return x;
    }

    // returns the indices of all states sorted by len, which is a
    // topological sort of both the transition graph and the reversed link tree.
    // runs in O(n).
    vector<int> order() {
        vector<int> out;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int i = q.front(); q.pop(), out.push_back(i);
            for (auto& [c, j] : adj[i])
                if (len[j] == len[i]+1) q.push(j);
        }
        return out;
    }

    // computes the sz array, runs in O(n).
    void refresh_sz() {
        fill(sz, sz+n, 0);
        auto o = order();
        for (int i = n-1; i > 0; i--) {
            if (!clo[o[i]]) sz[o[i]]++;
            sz[p[o[i]]] += sz[o[i]];
        }
        sz[0] = 0;
    }
};

const ll N = 1e5+5;
automaton<N> a;

ll dp[2*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s; ll n = s.size();
    ll k; cin >> k;
    for (auto& c : s) a.append(c);
    a.refresh_sz();
    auto o = a.order(); reverse(all(o));
    for (auto& i : o) {
        dp[i] = a.sz[i];
        for (auto& [c, j] : a.adj[i])
            dp[i] += dp[j];
    }
    if (k > n*(n+1)/2)
        return cout << "No such line.\n", 0;
    int x = 0;
    string out = "";
    while (k > a.sz[x]) {
        k -= a.sz[x];
        for (auto& [c, j] : a.adj[x]) {
            if (k > dp[j]) k -= dp[j];
            else {x = j; out += c; break;}
        }
    }
    cout << out << "\n";
}