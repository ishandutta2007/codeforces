#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[200105];
set<int> g[200105];
int u[200105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    int check = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!u[a[i]]) {
            u[a[i]] = 1;
            ++check;
        }
    }
    if (check != n || a[0] != 1) {
        cout << "No" << endl;
        exit(0);
    }
    queue<int> q;
    q.push(a[0]);
    int idx = 1;
    while (q.size() && idx < n) {
        int v = q.front();
        q.pop();
        for (int to : g[v])
            g[to].erase(v);
        while (idx < n) {
            if (g[v].count(a[idx]) == 0) {
                if (g[v].size() != 0) {
                    cout << "No" << endl;
                    exit(0);
                }
                break;
            }
            q.push(a[idx]);
            g[v].erase(a[idx]);
            ++idx;
        }
    }
    cout << (idx == n ? "Yes" : "No") << endl;
}