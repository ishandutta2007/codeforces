/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";


int n;
int a[55][55];


int get(int x, int y, int x1, int y1) {
    if (mp(x, y) > mp(x1, y1)) {
        swap(x, x1);
        swap(y, y1);
    }
    cout << '?' << ' ' << x << ' ' << y << ' ' << x1 << ' ' << y1 << endl;
    int res;
    cin >> res;
    return res;
}

vector<pair<int, int> > keks = {{1, 1}, {-1, -1}, {0, 2}, {0, -2}, {2, 0}, {-2, 0}};
bool used[55][55];

void dof(int i, int j) {
    used[i][j] = true;
    for (auto x: keks) {
        int i1 = i + x.first;
        int j1 = j + x.second;
        if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n && !used[i1][j1]) {
            int f = get(i1, j1, i, j);
            if (f) {
                a[i1][j1] = a[i][j];
            } else {
                a[i1][j1] = a[i][j] ^ 1;
            }
            dof(i1, j1);
        }
    }
}


void kek(int i, int j, int i1, int j1) {
    used[i][j] = true;
    used[i1][j1] = true;
    dof(i, j);
    dof(i1, j1);
    cout << "!" << endl;
    for (int ii = 1; ii <= n; ii++) {
        for (int jj = 1; jj <= n; jj++) {
            cout << a[ii][jj];
        }
        cout << endl;
    }
    exit(0);
}


int main() {
    ios_base::sync_with_stdio(false);
    //read(FILENAME); 
    cin >> n;
    a[1][1] = 1;
    a[n][n] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == n && j == n) continue;
            if ((i + j) % 2 != 0) continue; 
            if (i >= 3) {
                int f = get(i - 2, j, i, j);
                if (f) {
                    a[i][j] = a[i - 2][j];
                } else {
                    a[i][j] = !a[i - 2][j];
                }
                continue;
            }
            if (j >= 3) {
                int f = get(i, j - 2, i, j);
                if (f) {
                    a[i][j] = a[i][j - 2];
                } else {
                    a[i][j] = !a[i][j - 2];
                }
                continue;
            }
            if (i >= 2 && j >= 2) {
                int f = get(i - 1, j - 1, i, j);
                if (f) {
                    a[i][j] = a[i - 1][j - 1];
                } else {
                    a[i][j] = !a[i - 1][j - 1];
                }
                continue;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                if (i >= 2 && j + 1 <= n && a[i][j] != a[i - 1][j + 1]) {
                    int fi = -1;
                    int fj;
                    if (i - 2 >= 1) {
                        fi = i - 2;
                        fj = j;
                    }
                    if (j - 1 >= 1 && i - 1 >= 1) {
                        fi = i - 1;
                        fj = j - 1;
                    }
                    assert(fi != -1);
                    int s = get(fi, fj, i, j + 1);
                    if (s == 0) {
                        a[i][j + 1] = a[fi][fj] ^ 1;
                    } else {
                        a[i][j + 1] = a[fi][fj];
                    }
                    dof(i, j + 1);
                    cout << "!" << endl;
                    for (int ii = 1; ii <= n; ii++) {
                        for (int jj = 1; jj <= n; jj++) {
                            cout << a[ii][jj];
                        }
                        cout << endl;
                    }
                    exit(0);
                }
            }
        }
    }
    for (int i = 1; i <= n - 2; i++) {
        if (a[i][i] != a[i + 1][i + 1] && a[i + 1][i + 1] == a[i + 2][i + 2]) {
            int fi = i + 1;
            int fj = i;
            int fi1 = i + 2;
            int fj1 = i + 1;
            int g = get(fi, fj, fi1, fj1);
            if (g == 1) {
                int f1 = get(fi, fj, i + 2, i + 2);
                if (f1 == 0) {
                    a[fi][fj] = a[i + 2][i + 2] ^ 1;
                    a[fi1][fj1] = a[fi][fj];
                } else {
                    a[fi][fj] = a[i + 2][i + 2];
                    a[fi1][fj1] = a[fi][fj];
                }
            } else {
                int f1 = get(i, i, fi1, fj1);
                if (f1 == 0) {
                    a[fi][fj] = a[i][i] ^ 1;
                    a[fi1][fj1] = a[fi][fj] ^ 1;
                } else {
                    a[fi][fj] = a[i][i];
                    a[fi1][fj1] = a[fi][fj] ^ 1;
                }
            }
            kek(fi, fj, fi1, fj1);
        } else {
            if (a[i][i] == a[i + 1][i + 1] && a[i + 1][i + 1] != a[i + 2][i + 2]) {
                int fi = i + 1;
                int fj = i;
                int fi1 = i + 2;
                int fj1 = i + 1;
                int g = get(fi, fj, fi1, fj1);
                if (g == 1) {
                    int f1 = get(i, i, fi1, fj1);
                    if (f1 == 0) {
                        a[fi][fj] = a[i][i] ^ 1;
                        a[fi1][fj1] = a[fi][fj];
                    } else {
                        a[fi][fj] = a[i][i];
                        a[fi1][fj1] = a[fi][fj];
                    }
                } else {
                    int f1 = get(fi, fj, i + 2, i + 2);
                    if (f1 == 0) {
                        a[fi][fj] = a[i + 2][i + 2] ^ 1;
                        a[fi1][fj1] = a[fi][fj] ^ 1;
                    } else {
                        a[fi][fj] = a[i + 2][i + 2];
                        a[fi1][fj1] = a[fi][fj] ^ 1;
                    }
                }
                kek(fi, fj, fi1, fj1);
            }
        }
    }
    return 0; 
}