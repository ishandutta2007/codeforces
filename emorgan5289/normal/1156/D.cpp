#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

struct unionfind {

    int length;
    vector<int> parent, sz;

    unionfind(int s) {
        length = s;
        parent = vector<int>(s);
        sz = vector<int>(s, 1);
        for (int i = 0; i < s; i++)
            parent[i] = i;
    }

    int rep(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = rep(a);
        b = rep(b);
        if (a == b)
            return;
        parent[b] = a;
        sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    inline bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    inline int size(int x) {
        return sz[rep(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    unionfind a(n), b(n);
    for (int i = 0; i < n-1; i++) {
        int x, y, c; fin >> x >> y >> c;
        x--, y--;
        if (c) a.unite(x, y);
        else b.unite(x, y);
    }
    ll out = 0;
    for (int i = 0; i < n; i++)
        out += (ll)(a.size(i))*(ll)(b.size(i))-1ll;
    cout << out << "\n";
}