#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 43;
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

int ans = 0;
int n, m;

mt19937 rnd(0);

bool isin(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

int a[N][N];

int get() {
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == -1) {
                bool fl = false;
                for(int k = 0; k < 4; k++) {
                    int i1 = i + di[k];
                    int j1 = j + dj[k];

                    if(isin(i1, j1) && a[i1][j1] != -1) {
                        fl = true;
                        break;
                    }
                }
                if(!fl)
                    return -1;
                res++;
            }

        }
    }

    return res;
}

bool is1(int i2, int j2) {
    if(isin(i2, j2) && a[i2][j2] == -1) {
        bool fl = false;
        for(int k = 0; k < 4; k++) {
            int i1 = i2 + di[k];
            int j1 = j2 + dj[k];

            if(isin(i1, j1) && a[i1][j1] != -1) {
                fl = true;
                break;
            }
        }
        if(!fl)
            return false;
    }
    return true;
}

bool is2(int i2, int j2) {
    if(isin(i2, j2) && a[i2][j2] == -1) {
        bool fl = false;
        for(int k = 0; k < 4; k++) {
            int i1 = i2 + di[k];
            int j1 = j2 + dj[k];

            if(isin(i1, j1) && a[i1][j1] == 1) {
                fl = true;
                break;
            }
        }
        if(!fl)
            return false;
    }
    return true;
}

void calc(int i, int j, int cur) {
    if(cur >= ans)
        return;

    if(i == n) {
//        int res = get();
        if(!is2(n - 1, m - 1))
            return;

//        assert(get() != -1);
//        if(get() != -1) {
//            cout << cur << endl;
//            for(int i1 = 0; i1 < n; i1++) {
//                for(int j1 = 0; j1 < m; j1++) {
//                    cout << a[i1][j1] << ' ';
//                }
//                cout << endl;
//            }
//            exit(0);
//        }
//        if(ans > cur) {
//            cout << cur << endl;
//            for(int i1 = 0; i1 < n; i1++) {
//                for(int j1 = 0; j1 < m; j1++) {
//                    cout << a[i1][j1] << ' ';
//                }
//                cout << endl;
//            }
//        }

//        ans = min(ans, n * m - res);

        ans = min(ans, cur);

        return;
    }

//    int i2 = (j == 0 ? i - 2 : i - 1), j2 = (j == 0 ? m - 1 : j - 1);
////    cout << i << ' ' << j << ' ' << i2 << ' ' << j2 << endl;
//    if(isin(i2, j2) && a[i2][j2] == -1) {
//        bool fl = false;
//        for(int k = 0; k < 4; k++) {
//            int i1 = i2 + di[k];
//            int j1 = j2 + dj[k];
//
//            if(isin(i1, j1) && a[i1][j1] != -1) {
//                fl = true;
//                break;
//            }
//        }
//        if(!fl)
//            return;
//    }
//
//
//    vector<int> p = {-1, 1};
//    if(rnd() & 1)
//        swap(p[0], p[1]);

    int i1 = i + (j == m - 1), j1 = (j == m - 1 ? 0 : j + 1);
    if(i != 0 && !is2(i - 1, j) || i == n - 1 && j > 0 && !is2(i, j - 1)) {
        a[i][j] = 1;
        calc(i1, j1, cur + 1);
    } else {
        a[i][j] = 1;
        calc(i1, j1, cur + 1);
        a[i][j] = -1;
        calc(i1, j1, cur);
    }

    a[i][j] = 0;
}

int main() {

    cin >> n >> m;
    if(n > m)
        swap(n, m);
    ans = n * m;//(n * m + 2) / 3;
    ans = (n * m + 2) / 3;

//    if(n > 1)
        calc(0, 0, 0);

    cout << n * m - ans << endl;
}