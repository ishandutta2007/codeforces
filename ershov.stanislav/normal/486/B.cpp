#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000111;

int n, m, a[111][111], b[111][111], c[111][111];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            bool flag = true;
            for (int k = 0; k < m; k ++) {
                if (!a[k][j]) flag = false;
            }
            for (int k = 0; k < n; k ++) {
                if (!a[i][k]) flag = false;
            }
            if (flag) b[i][j] = 1;
        }
    }
    bool res = true;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j ++) {
            bool aa = false;
            for (int k = 0; k < m; k ++) {
                if (b[k][j]) aa = true;
            }
            for (int k = 0; k < n; k ++) {
                if (b[i][k]) aa = true;
            }
            if (aa) c[i][j] = 1;
            if (c[i][j]!=a[i][j]) {
                res = false;
            }
        }
    }
    if (res) {
        cout << "YES\n";
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j ++) {
                cout << b[i][j] << ' ';
            }
            cout << endl;
        }
    } else cout << "NO\n";
    return 0;
}