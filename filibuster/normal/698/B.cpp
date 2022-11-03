#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
10000 1000000000 1 1000000000 10000
*/

int p[N];
vector<int> g[N];
int ans = 0;
int used[N];
int root = -1;

int dfs1(int v) {
    if(v == root) {
        return -1;
    }

    used[v] = 1;

    int u = p[v];
    int res = -1;
    if(used[u] == 0) {
        res = dfs1(u);
    } else if(used[u] == 1) {
        res = u;
    }

    used[v] = 2;
    return res;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;


    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < n; i++) {
        if(p[i] == i) {
            if(root == -1) {
                root = i;
            } else {
                ans++;
                p[i] = root;
            }
        }

        g[p[i]].push_back(i);
    }

//    cout << ans << endl;

    if(root == -1) {
        root = dfs1(0);
        p[root] = root;
        ans++;
    }
//cout << ans << endl;
    for(int i = 0; i < n; i++) {
//            cout << i << ' ' << ans <<endl;
        if(used[i] == 0) {
            int v = dfs1(i);
            if(v != -1) {
                ans++;
                p[v] = root;
            }
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        cout << p[i] + 1 << ' ';
    }
}