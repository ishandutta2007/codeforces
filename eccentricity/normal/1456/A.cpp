#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 2;
char s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, p, k, x, y;
        cin >> n >> p >> k;
        cin >> (s + 1) >> x >> y;
        int ans = 1E9;
        for(int i = n; i >= n - k + 1; i -= 1){
            for(int j = i, z = 0; j >= p; j -= k){
                z += s[j] == '0';
                ans = min(ans, z * x + y * (j - p));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}