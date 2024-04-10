#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 40000
#define MNn 200
#define MM 1000
#define MX 1000000
#define INF 1000000000
using namespace std;
bool swap_flag;
int n, m, K, T, ans;
vector<int> v[MN + 5];
int X, num[MX * 2 + 5], Num[MM * 2 + 5];

inline int id(int x, int y) { return (x - 1) * m + y;}
inline int blockof(int w) { return w / MM; }

inline void Add(int x) {
    if (!num[x]++) ++Num[blockof(x)];
}

inline void Del(int x) {
    if (!--num[x]) --Num[blockof(x)];
}

void Clear(int x, int y, int l) {
    for (int i = 0; i < l; ++i) {
        int ID = id(x, y + i);
        for (int j = 0; j < v[ID].size(); ++j) {
            Del(v[ID][j]);
        }
    }
    for (int i = 1; i < l; ++i) {
        int ID = id(x + i, y);
        for (int j = 0; j < v[ID].size(); ++j) {
            Del(v[ID][j]);
        }
    }
}

void Enlarge(int x, int y, int l) {
    int xx = x + l - 1, yy = y + l - 1;
    for (int i = 0; i < l; ++i) {
        int ID = id(x + i, yy);
        for (int j = 0; j < v[ID].size(); ++j) {
            Add(v[ID][j]);
        }
    }
    for (int i = 0; i < l - 1; ++i) {
        int ID = id(xx, y + i);
        for (int j = 0; j < v[ID].size(); ++j) {
            Add(v[ID][j]);
        }
    }
}

inline bool BlockOK(int b) { return Num[b] == MM; }

bool OK() {
    // cout <<" OK"; fflush(stdout);
    int cnt = 0, i = 999, j = 1000;
    while(i >= 0 && cnt < T) {
        if (BlockOK(i)) {
            cnt += MM;
            --i;
        }  else {
            break;
        }
    }
    while (j <= 2 * MM && cnt < T) {
        if (BlockOK(j)) {
            cnt += MM;
            ++j;
        } else {
            break;
        }
    }
    // cout << " start from " << i << " " << j << " " << NumOK[i] << " " << NumOK[j] << endl;
    if (i >= 0 && cnt < T) {
        for (int k = (i + 1) * MM; --k >= 0;) {
            if (num[k] > 0) {
                ++ cnt;
            } else {
                break;
            }
        }
    }
    if (j <= 2 * MM && cnt < T) {
        for (int k = j * MM; ; ++k) {
            if (num[k] > 0) {
                ++ cnt;
            } else {
                break;
            }
        }
    }
    // printf("OK found %d\n", cnt);
    return cnt >= T;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &K, &T); T = max(1, T - 1);
    if (n > m) {
        swap_flag = true;
        swap(n, m);
    }
    for (int i = 1, x, y, w; i <= K; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        if (swap_flag) swap(x, y);
        if (max(w, -w) > T) continue;
        if (w > 0) {
            w += MX - 1;
        } else {
            w += MX;
        }
        v[id(x, y)].push_back(w);
    }
    for (int i = 1; i <= n * m; ++i) sort(v[i].begin(), v[i].end());
    for (int ii = n, jj = 1; jj <= m; ii > 1 ? --ii : ++jj) {
        int l = 0;
        for (int i = ii, j = jj; i <= n && j <= m; ++i, ++j) {
            bool ok = OK();
            while (!ok && i + l <= n && j + l <= m) {
                Enlarge(i, j, ++l);
                ok = OK();
            }
            if (!ok) {
                // if (ii > 1) printf("GG %d %d %d\n", i, j, l);
                for (int x = 0; x < l; ++x) {
                    for (int y = 0; y < l; ++y) {
                        int ID = id(i + x, j + y);
                        for (int j = 0; j < v[ID].size(); ++j) {
                            Del(v[ID][j]);
                        }
                    }
                }
                break;
            }
            // if (ii > 1)
            // printf("%d %d %d %d\n", i, j, l, OK());
            ans += min(n - (i + l - 1) + 1, m - (j + l - 1) + 1);
            Clear(i, j, l); --l;
        }
    }
    cout << ans;
    return 0;
}