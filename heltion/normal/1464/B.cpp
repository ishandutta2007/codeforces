#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int bit[maxn];
char s[maxn + 1];
void add(int x, int d){
    for(; x < maxn; x += x & -x) bit[x] += d;
}
int sum(int x){
    int res = 0;
    for(; x; x -= x & -x) res += bit[x];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL x, y;
    cin >> (s + 1) >> x >> y;
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i += 1){
        if(s[i] == '1') add(i, 1);
    }
    LL pans = 0;
    for(int i = 1; i <= n; i += 1)
        if(s[i] == '1') pans += (i - sum(i)) * x + ((n - i) - (sum(n) - sum(i))) * y;
    LL ans = pans;
    for(int i = 1; i <= n; i += 1)
        if(s[i] == '?'){
            pans -= (sum(i)) * y + (sum(n) - sum(i)) * x;
            add(i, 1);
            pans += (i - sum(i)) * x + ((n - i) - (sum(n) - sum(i))) * y;
            ans = min(ans, pans);
        }
    
    for(int i = 1; i <= n; i += 1)
        if(s[i] == '?'){
            pans -= (i - sum(i)) * x + ((n - i) - (sum(n) - sum(i))) * y;
            add(i, -1);
            pans += (sum(i)) * y + (sum(n) - sum(i)) * x;
            ans = min(ans, pans);
        }
    cout << ans;
    return 0;
}