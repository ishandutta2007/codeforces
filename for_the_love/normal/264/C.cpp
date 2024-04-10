#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1e18;
int n, m, i, r1, r2, c[100005];
long long dp[100005], v[100005], m1, m2, a, b;
int main(){
    cin >> n >> m;
    for (i = 1; i <= n; i++) cin >> v[i];
    for (i = 1; i <= n; i++) cin >> c[i];
    while (m--){
        cin >> a >> b;
        m1 = m2 = - inf;  r1 = r2 = 0;
        for (i = 1; i <= n; i++) dp[i] = -inf;
        for (i = 1; i <= n; i++){
            dp[c[i]] = max(dp[c[i]], max(dp[c[i]] + v[i] * a, v[i] * b));
            if (r1 == c[i]) dp[c[i]] = max(dp[c[i]], m2 + v[i] * b); else dp[c[i]] = max(dp[c[i]], m1 + v[i] * b);
            if (dp[c[i]] > m1){
                if (c[i] == r1) m1 = dp[c[i]];
                else{
                    m2 = m1;
                    r2 = r1;
                    m1 = dp[c[i]];
                    r1 = c[i];
                }
            }else
            if (dp[c[i]] > m2 && c[i] != r1){
                m2 = dp[c[i]];
                r2 = c[i];
            }
        }
        if (m1 > 0) cout << m1 << endl; else cout << "0" << endl;
    }
}