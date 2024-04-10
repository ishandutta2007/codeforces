#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn], b[maxn], ma[maxn][20];
int LOG[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        for(int i = 2; i <= n; i += 1) LOG[i] = LOG[i / 2] + 1;
        cin >> m;
        for(int i = 1; i <= n; i += 1) b[i] = 0;
        for(int i = 1, p, s; i <= m; i += 1){
            cin >> p >> s;
            b[s] = max(b[s], p);
        }
        for(int i = n - 1; i; i -= 1) b[i] = max(b[i + 1], b[i]);
        for(int i = n; i; i -= 1){
            ma[i][0] = a[i];
            for(int j = 1; i + (1 << j) - 1 <= n; j += 1) ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        }
        bool fail = false;
        int ans = 0;
        for(int L = 1, R = 1; L <= n and not fail; L = R += 1){
            if(a[L] > b[1]){
                fail = true;
                break;
            }
            int l = L;
            R = n;
            while(l < R){
                int M = (l + R + 1) >> 1;
                int j = LOG[M - L + 1];
                int m = max(ma[L][j], ma[M - (1 << j) + 1][j]);
                if(m > b[M - L + 1]) R = M - 1;
                else l = M;
            }
            ans += 1;
        }
        cout << (fail ? -1 : ans) << "\n";
    }
    return 0;
}