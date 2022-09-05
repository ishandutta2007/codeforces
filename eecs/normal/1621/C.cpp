#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int T, n, p[maxn];
bool vis[maxn];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            vector<int> V;
            while (1) {
                cout << "? " << i << endl;
                int x; cin >> x;
                if (vis[x]) break;
                V.push_back(x), vis[x] = 1;
            }
            for (int j = 0; j < V.size(); j++) {
                p[V[j]] = V[(j + 1) % V.size()];
            }
        }
        cout << "!";
        for (int i = 1; i <= n; i++) {
            cout << " " << p[i];
        }
        cout << endl;
    }
    return 0;
}