#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000 + 1;
char s[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> s[i];
        for(int d = 0; d < 10; d += 1){
            int xL = n, xR = -1, yL = n, yR = -1;
            for(int i = 0; i < n; i += 1)
                for(int j = 0; j < n; j += 1) if(s[i][j] == '0' + d){
                    xL = min(xL, i);
                    xR = max(xR, i);
                    yL = min(yL, j);
                    yR = max(yR, j);
                }
            int ans = 0;
            for(int i = 0; i < n; i += 1){
                int yL = n, yR = -1;
                for(int j = 0; j < n; j += 1) if(s[i][j] == '0' + d){
                    yL = min(yL, j);
                    yR = max(yR, j);
                    ans = max(ans, max(i - xL, xR - i) * max(n - 1 - j, j));
                }
                if(yR != -1) ans = max(ans, (yR - yL) * max(n - 1 - i, i));
            }
            for(int i = 0; i < n; i += 1){
                int xL = n, xR = -1;
                for(int j = 0; j < n; j += 1) if(s[j][i] == '0' + d){
                    xL = min(xL, j);
                    xR = max(xR, j);
                    ans = max(ans, max(i - yL, yR - i) * max(n - 1 - j, j));
                }
                if(xR != -1) ans = max(ans, (xR - xL) * max(n - 1 - i, i));
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}