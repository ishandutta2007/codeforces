#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

#define mod 1000000007ll
#define maxn 2020
bool a[maxn][maxn];
ll h[maxn][maxn], v[maxn][maxn], sh[maxn][maxn], sv[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; fin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            char c; fin >> c; a[i][j] = c == 'R';
        }
    for (int i = n-1; i >= 0; i--)
        for (int j = m-1; j >= 0; j--) {
            sh[i][j] = (j == m-1 ? 0 : sh[i][j+1]) + (a[i][j] ? 1 : 0);
            sv[i][j] = (i == n-1 ? 0 : sv[i+1][j]) + (a[i][j] ? 1 : 0);
            h[i][j] = j == m-1 ? 0 : h[i][j+1] + v[i][j+1] + mod - (a[i][j+1] ? v[i][m-sh[i][j+1]] : 0);
            v[i][j] = i == n-1 ? 0 : v[i+1][j] + h[i+1][j] + mod - (a[i+1][j] ? h[n-sv[i+1][j]][j] : 0);
            h[i][j] %= mod; v[i][j] %= mod;
            if (i == n-1) h[i][j] = sh[i][j] ? 0 : 1;
            if (j == m-1) v[i][j] = sv[i][j] ? 0 : 1;
        }
    cout << (n == 1 && m == 1 ? 1 : (h[0][0]+v[0][0])%mod) << "\n";
}