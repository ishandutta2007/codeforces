#include <bits/stdc++.h>

using namespace std;

int n, m;
int par[1000];

int main() {
    scanf("%d%d", &n, &m);
    if (m != n - 1) {
        cout << "no" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        a = par[a];
        b = par[b];
        if (a == b) {
            cout << "no" << endl;
            return 0;
        }
        for (int j = 0; j < n; ++j) {
            if (par[j] == a) {
                par[j] = b;
            }
        }
    }
    cout << "yes" << endl;
    return 0;
}