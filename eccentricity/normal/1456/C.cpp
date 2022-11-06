#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000 + 1;
LL c[maxn];
LL pn[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1) cin >> c[i];
    sort(c + 1, c + n + 1, greater<LL>());
    LL ans = 0, sum = 0;
    int x = 1;
    for(x = 1; x <= n; x += 1){
        ans += sum;
        sum += c[x];
        if(sum < 0) break;
    }
    if(sum >= 0){
        cout << ans;
        return 0;
    }
    vector<LL> ne;
    ne.push_back(sum);
    for(int i = x + 1; i <= n; i += 1) ne.push_back(c[i]);
    sort(ne.begin(), ne.end());
    for(int i = 0; i < ne.size(); i += 1) ans += ne[i] * (i / (k + 1));
    cout << ans;
    return 0;
}