#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
const int N = 51;
int n;
bool ans[N][N];
int Q = 0;
int get(int x1, int y1, int x2, int y2) {
    ++Q;
    if (Q > n * n) {
        cout << "Q\n";
        exit(1);
    }
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    fflush(stdout);
    int ans; cin >> ans; return ans;
}
 
bool us[N][N];
 
void calc(bool l, bool r, bool x, bool &a, bool &b, bool c1, bool c2, bool dif) {
    if (c1) {
        a = r; b = a ^ dif;
    }   
    else if (c2) {
        b = l; a = b ^ dif;
    }
    else if (!dif) {
        a = b = x ^ 1;
    }
    else if (x == l) {
        a = x;
        b = x ^ 1;  
    }
    else {
        a = x ^ 1;
        b = x;
    }    
}
void go(int i, int j) {
    while (i - 1 >= 1 && j - 1 >= 1) {
        if (get(i - 1, j - 1, i, j)) ans[i - 1][j - 1] = ans[i][j];
        else ans[i - 1][j - 1] = !ans[i][j];
        --i; --j; us[i][j] = 1;
    }
}
signed main() {
    ans[1][1] = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            if (i == n && j == n) continue;
            if (abs(i - j) % 2 == 0) {
                if (i - 2 >= 1) {
                    if (get(i - 2, j, i, j)) ans[i][j] = ans[i - 2][j];
                    else ans[i][j] = !ans[i - 2][j];
                }
                else if (j - 2 >= 1) {
                    if (get(i, j - 2, i, j)) ans[i][j] = ans[i][j - 2];
                    else ans[i][j] = !ans[i][j - 2];
                }
                else {
                    if (get(i - 1, j - 1, i, j)) ans[i][j] = ans[i - 1][j - 1];
                    else ans[i][j] = !ans[i - 1][j - 1];
                }
            }   
        }
    }   
    for (int i = 1; ; ++i) {
        if (ans[i][i] != ans[i + 2][i + 2]) {
 
            bool c1 = get(i, i + 1, i + 2, i + 2);
            bool c2 = get(i, i, i + 1, i + 2);
            bool dif = get(i, i + 1, i + 1, i + 2) ^ 1;
            calc(ans[i][i], ans[i + 2][i + 2], ans[i][i + 2], ans[i][i + 1], ans[i + 1][i + 2], c1, c2, dif);
 
            if (get(i + 1, i, i + 1, i + 2)) ans[i + 1][i] = ans[i + 1][i + 2];
            else ans[i + 1][i] = !ans[i + 1][i + 2];
 
            if (get(i, i + 1, i + 2, i + 1)) ans[i + 2][i + 1] = ans[i][i + 1];
            else ans[i + 2][i + 1] = !ans[i][i + 1];
 
            us[i][i + 1] = us[i + 1][i + 2] = us[i + 1][i] = us[i + 2][i + 1] = 1;
            go(i, i + 1); go(i + 1, i);
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (us[i][j]) continue;
            if (abs(i - j) & 1) {
                if (i - 2 >= 1) {
                    if (get(i - 2, j, i, j)) ans[i][j] = ans[i - 2][j];
                    else ans[i][j] = !ans[i - 2][j];
                }
                else if (j - 2 >= 1) {
                    if (get(i, j - 2, i, j)) ans[i][j] = ans[i][j - 2];
                    else ans[i][j] = !ans[i][j - 2];
                }
                else {
                    if (get(i - 1, j - 1, i, j)) ans[i][j] = ans[i - 1][j - 1];
                    else ans[i][j] = !ans[i - 1][j - 1];
                }
            }
        }
    }
    cout << "!\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    fflush(stdout);
}