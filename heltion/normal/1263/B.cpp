#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
char s[10][5];
bool check(int i, int n){
    for(int j = 0; j < n; j += 1)
        if(i != j and string(s[i]) == s[j]) return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> s[i];
        int ans = 0;
        for(int i = 0; i < n; i += 1){
            if(check(i, n)) continue;
            ans += 1;
            for(int j = 0; j < 10; j += 1){
                s[i][0] = '0' + j;
                if(check(i, n)) break;
            }
        }
        cout << ans << "\n";
        for(int i = 0; i < n; i += 1) cout << s[i] << "\n";
    }
    return 0;
}