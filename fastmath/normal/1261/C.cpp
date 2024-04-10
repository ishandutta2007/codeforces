#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;
int n, m;
string a[N];
vector <int> p[N];
void ban(int x1, int y1, int x2, int y2) {
    x1 = max(x1, 0);
    y1 = max(y1, 0);
    x2 = min(x2, n - 1);
    y2 = min(y2, m - 1);
    if (x2 < x1 || y2 < y1) return;
    ++p[x1][y1];
    if (y2 + 1 < m) --p[x1][y2 + 1];
    if (x2 + 1 < n) --p[x2 + 1][y1];
    if (x2 + 1 < n && y2 + 1 < m) ++p[x2 + 1][y2 + 1];
}   
inline int get(int x, int y) {
    if (x < 0 || y < 0) return 0;
    else return p[x][y];
}   
int sum(int x1, int y1, int x2, int y2) {
    x1 = max(x1, 0);
    y1 = max(y1, 0);
    x2 = min(x2, n - 1);
    y2 = min(y2, m - 1);
    return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
}   
bool check(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}
vector <bool> can[N];
bool check(int mid) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            p[i][j] = 0;
    for (int i = -1; i <= n; ++i) {
        for (int j = -1; j <= m; ++j) {
            if (!check(i, j) || a[i][j] == '.') {
                ban(i - mid, j - mid, i + mid, j + mid);                
            }
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i) p[i][j] += p[i - 1][j];
            if (j) p[i][j] += p[i][j - 1];
            if (i && j) p[i][j] -= p[i - 1][j - 1];
            can[i][j] = !p[i][j];
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p[i][j] = can[i][j];
            if (i) p[i][j] += p[i - 1][j];
            if (j) p[i][j] += p[i][j - 1];
            if (i && j) p[i][j] -= p[i - 1][j - 1];            
        }   
    }   
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (a[i][j] == 'X') {
                if (!sum(i - mid, j - mid, i + mid, j + mid)) return 0;
            }       
    return 1;
}   
void print(int mid) {
    cout << mid << '\n';
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            p[i][j] = 0;
    for (int i = -1; i <= n; ++i) {
        for (int j = -1; j <= m; ++j) {
            if (!check(i, j) || a[i][j] == '.') {
                ban(i - mid, j - mid, i + mid, j + mid);                
            }
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i) p[i][j] += p[i - 1][j];
            if (j) p[i][j] += p[i][j - 1];
            if (i && j) p[i][j] -= p[i - 1][j - 1];
            can[i][j] = !p[i][j];
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            if (can[i][j]) 
                cout << 'X';
            else 
                cout << '.';
        cout << '\n';
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        p[i].resize(m);
        can[i].resize(m);
    }
    int l = 0, r = 2007;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }   
    print(l);
}