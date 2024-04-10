#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int N = 555;
int a[N][N], b[N][N];

int _geta(int x, int y){
    if (x < 0 || y < 0)
        return 0;
    else
        return a[x][y];
}

int _getb(int x, int y){
    if (x < 0 || y < 0)
        return 0;
    else
        return b[x][y];
}

inline int get(int u, int l, int d, int r){
    return _geta(d, r - 1) - _geta(d, l - 1) - _geta(u - 1, r - 1) + _geta(u - 1, l - 1) + 
           _getb(d - 1, r) - _getb(d - 1, l - 1) - _getb(u - 1, r) + _getb(u - 1, l - 1);
}

int main(){

    int n = nxt(), m = nxt();
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m - 1; j++){
            if (s[i][j] == '.' && s[i][j + 1] == '.')
                a[i][j] = 1;
        }
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == '.' && s[i + 1][j] == '.')
                b[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0){
                if (j != 0){
                    a[i][j] += a[i][j - 1];
                    b[i][j] += b[i][j - 1];
                }
            } else
            if (j == 0){
                a[i][j] += a[i - 1][j];
                b[i][j] += b[i - 1][j];
            } else {
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            }
        }
    }

    // for (int i = 0; i < n - 1; i++){
    //  for (int j = 0; j < m; j++){
    //      cerr << b[i][j] << " ";
    //  }
    //  cerr << "\n";
    // }
    // cerr << "\n";

    int q = nxt();
    while (q--){
        int u = nxt() - 1, l = nxt() - 1, d = nxt() - 1, r = nxt() - 1;
        printf("%d\n", get(u, l, d, r));
    }

    return 0;
}