#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
LL a[maxn], s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    set<LL> ss;
    LL ans = 0;
    for(int L = 0, R = -1; L <= n; L += 1){
        while(R < n and not ss.count(s[R + 1])){
            ss.insert(s[R + 1]);
            R += 1;
        }
        ans += R - L;
        ss.erase(s[L]);
    }
    cout << ans;
    return 0;
}