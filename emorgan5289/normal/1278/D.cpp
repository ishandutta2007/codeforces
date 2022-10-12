#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

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
    vector<int> parent;

    unionfind(int s) {
        length = s;
        parent = vector<int>(s);
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
    }

    // returns true if a and b are in the same set.
    inline bool query(int a, int b) {
        return rep(a) == rep(b);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<pair<int, int>> a(n);
    for (auto& x : a) fin >> x.first >> x.second;
    sort(all(a));
    unionfind u(n);
    map<int, int> s;
    debug(a);
    for (int i = 0; i < n; i++) {
        int x, y; tie(x, y) = a[i];
        for (auto it = s.upper_bound(x); it != s.upper_bound(y); it++) {
            int j = it->second;
            debug(i, j, it->first, x, y);
            if (u.query(i, j)) {
                cout << "NO\n"; return 0;
            }
            u.unite(i, j);
        }
        s[y] = i;
    }
    int x = u.rep(0);
    for (int i = 1; i < n; i++)
        if (u.rep(i) != x) {
            cout << "NO\n"; return 0;
        }
    cout << "YES\n";
}