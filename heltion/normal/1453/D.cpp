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
        LL k, ans = 0;
        cin >> k;
        if(k & 1){
            cout << "-1\n";
            continue;
        }
        vector<LL> v;
        while(k){
            LL n = 1;
            while((1LL << (n + 2)) - 2 <= k) n += 1;
            v.push_back(n);
            ans += n;
            k -= (1LL << (n + 1)) - 2;
        }
        cout << ans << "\n";
        for(LL x : v){
            cout << "1 ";
            for(LL i = 1; i < x; i += 1) cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}