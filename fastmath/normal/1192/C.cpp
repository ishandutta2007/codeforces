#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define ll long long
const int N = 1e5 + 7;
const int A = 62;
const int MOD = 998244353;
ll f[A][A];
ll sum[A][A][A];
int ans = 0;
int get(int a, int b, int c) {
    vector <int> t = {a, b, c};
    sort(t.begin(), t.end());
    return sum[t[0]][t[1]][t[2]];
}   
inline int mod(long long n) {
    if (n < MOD) return n;
    else if (n < 2 * MOD) return n - MOD;
    return n % MOD;
}   
void solve() {
    for (int i = 0; i < A; ++i) {
        for (int j = i; j < A; ++j) {
            for (int k = j; k < A; ++k) {
 
                sum[i][j][k] = 0;
                for (int t = 0; t < A; ++t) {
                    sum[i][j][k] += f[t][i] * f[t][j] * f[t][k];
                }
                sum[i][j][k] = mod(sum[i][j][k]); 
 
            }   
        }   
    }   
 
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            for (int k = 0; k < A; ++k) {
                sum[i][j][k] = get(i, j, k);    
            }   
        }   
    }   
 
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            for (int k = 0; k < A; ++k) {
                ll s = 0;
                for (int t = 0; t < A; ++t) {
                    s += mod(mod(sum[j][k][t] * sum[i][k][t]) * sum[i][j][t]);
                }   
                s = mod(s); 
                ans = mod(ans + sum[i][j][k] * s);
            }   
        }   
    }   
}   
int n;
string a[N];
int num(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    else if ('A' <= c && c <= 'Z') return c - 'A' + 26;
    else return c - '0' + 52;
}   
int solve(int len) {
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            f[i][j] = 0;
        }   
    }   
    for (int i = 0; i < n; ++i) {
        if (a[i].size() == len) {
            int l = num(a[i][0]), r = num(a[i][len - 1]);
 
            auto t = a[i];
            reverse(t.begin(), t.end());
            if (a[i] == t) {
                ++f[l][r];
            }   
            else {
                ++f[l][r]; ++f[r][l];
            }   
        }      
    }
    solve();
}
#ifdef HOME
double get_time() {
    return (double)clock()/CLOCKS_PER_SEC;
}   
#endif  
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        auto t = a[i];
        reverse(t.begin(), t.end());
        if (t < a[i]) a[i] = t;
    }   
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int len = 3; len <= 10; ++len) {
        solve(len);
    }   
    cout << ans << '\n';
    #ifdef HOME
    cout << get_time() << '\n';
    #endif
}