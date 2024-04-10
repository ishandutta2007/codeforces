#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, col[maxn], bel[maxn], ans[maxn];
string str;
vector<int> V, res[4];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n > 1) {
            cout << "Q " << n / 2;
            for (int i = 1; i < n; i += 2) {
                cout << " " << i << " " << i + 1;
            }
            cout << endl;
            cin >> str;
            for (int i = 1; i < n; i += 2) {
                col[i] = str[i / 2] - '0';
            }
        }
        if (n > 2) {
            cout << "Q " << (n - 1) / 2;
            for (int i = 2; i < n; i += 2) {
                cout << " " << i << " " << i + 1;
            }
            cout << endl;
            cin >> str;
            for (int i = 2; i < n; i += 2) {
                col[i] = str[i / 2 - 1] - '0';
            }
        }
        V.clear(), res[1].clear(), res[2].clear(), res[3].clear();
        for (int i = 1; i <= n; i++) {
            if (i == 1 || !col[i - 1]) V.push_back(bel[i] = i);
            else bel[i] = bel[i - 1];
        }
        if (V.size() > 2) {
            int t = 0;
            for (int i = 0; i + 2 < V.size(); i += 4) {
                t++;
                if (i + 3 < V.size()) t++;
            }
            cout << "Q " << t;
            for (int i = 0; i + 2 < V.size(); i += 4) {
                cout << " " << V[i] << " " << V[i + 2];
                if (i + 3 < V.size()) cout << " " << V[i + 1] << " " << V[i + 3];
            }
            cout << endl;
            cin >> str;
            for (int i = 0, j = 0; i + 2 < V.size(); i += 4) {
                col[i] = str[j++] - '0';
                if (i + 3 < V.size()) col[i + 1] = str[j++] - '0';
            }
        }
        if (V.size() > 4) {
            int t = 0;
            for (int i = 2; i + 2 < V.size(); i += 4) {
                t++;
                if (i + 3 < V.size()) t++;
            }
            cout << "Q " << t;
            for (int i = 2; i + 2 < V.size(); i += 4) {
                cout << " " << V[i] << " " << V[i + 2];
                if (i + 3 < V.size()) cout << " " << V[i + 1] << " " << V[i + 3];
            }
            cout << endl;
            cin >> str;
            for (int i = 2, j = 0; i + 2 < V.size(); i += 4) {
                col[i] = str[j++] - '0';
                if (i + 3 < V.size()) col[i + 1] = str[j++] - '0';
            }
        }
        ans[V[0]] = 1;
        if (V.size() > 1) ans[V[1]] = 2;
        for (int i = 2; i < V.size(); i++) {
            if (!col[i - 2]) ans[V[i]] = ans[V[i - 2]] ^ ans[V[i - 1]];
            else ans[V[i]] = ans[V[i - 2]];
        }
        for (int i = 1; i <= n; i++) {
            res[ans[bel[i]]].push_back(i);
        }
        cout << "A " << res[1].size() << " " << res[2].size() << " " << res[3].size() << endl;
        for (int x : res[1]) cout << x << " ";
        cout << endl;
        for (int x : res[2]) cout << x << " ";
        cout << endl;
        for (int x : res[3]) cout << x << " ";
        cout << endl;
    }
    return 0;
}