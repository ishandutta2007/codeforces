#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
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

const int bits = 32;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n, m; fin >> n >> m;

        vector<bool> b(n*m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char c; fin >> c;
                b[i*m+j] = c == '0';
            }

        vector<vector<int>> a(bits, vector<int>(n*m));
        vector<int> indeg(n*m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char c; fin >> c;
                if (c == 'D') a[0][i*m+j] = (i+1)*m+(j);
                if (c == 'U') a[0][i*m+j] = (i-1)*m+(j);
                if (c == 'R') a[0][i*m+j] = (i)*m+(j+1);
                if (c == 'L') a[0][i*m+j] = (i)*m+(j-1);
                indeg[a[0][i*m+j]]++;
            }

        int out1 = n*m, out2 = 0;

        vector<int> stack, dfs;
        for (int i = 0; i < n*m; i++)
            if (indeg[i] == 0)
                stack.pb(i);
        while (!stack.empty()) {
            int i = stack.back(); stack.pop_back();
            indeg[a[0][i]]--;
            out1--;
            dfs.pb(i);
            if (indeg[a[0][i]] == 0)
                stack.pb(a[0][i]);
        }

        for (int i = 1; i < bits; i++)
            for (int j = 0; j < n*m; j++)
                a[i][j] = a[i-1][a[i-1][j]];

        unionfind cyc(n*m);
        for (int i = 0; i < n*m; i++)
            if (indeg[i])
                cyc.unite(i, a[0][i]);

        vector<int> d(n*m, 0);
        for (int i = dfs.size()-1; i >= 0; i--) {
            if (indeg[a[0][dfs[i]]])
                d[dfs[i]] = cyc.size(a[0][dfs[i]])*(n*m/cyc.size(a[0][dfs[i]]));
            else
                d[dfs[i]] = d[a[0][dfs[i]]];

            int k = dfs[i];
            for (int j = 0; j < bits; j++)
                if (d[dfs[i]]&(1<<j))
                    k = a[j][k];

            b[k] = b[k] || b[dfs[i]];
        }

        for (int i = 0; i < n*m; i++)
            if (b[i] && indeg[i])
                out2++;
        cout << out1 << " " << out2 << "\n";
    }
}