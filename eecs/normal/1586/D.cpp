#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, p[maxn], pre[maxn], mark[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "?";
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << " 2";
            else cout << " 1";
        }
        cout << endl;
        int k; cin >> k;
        if (k && k != i) pre[k] = i, mark[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << "?";
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << " 1";
            else cout << " 2";
        }
        cout << endl;
        int k; cin >> k;
        if (k && k != i) pre[i] = k, mark[k] = 1;
    }
    for (int i = 1; i <= n; i++) if (!mark[i]) {
        p[i] = n;
        int cur = n;
        for (int j = pre[i]; j; j = pre[j]) p[j] = --cur;
        break;
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << p[i];
    }
    cout << endl;
    return 0;
}