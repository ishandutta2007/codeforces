#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int s[maxn], c[maxn], m[maxn];
vector<int> v[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i += 1){
        cin >> m[i];
        s[m[i]] += 1;
    }
    sort(m, m + n, greater<int>());
    for(int i = k - 1; i >= 1; i -= 1) s[i] += s[i + 1];
    for(int i = 1; i <= k; i += 1) cin >> c[i];
    int ans = 0;
    for(int i = 1; i <= k; i += 1)
        ans = max((s[i] + c[i] - 1) / c[i], ans);
    for(int i = 0, j = 0; j < n; i = (i + 1) % ans, j += 1)
        v[i].push_back(m[j]);
    cout << ans << "\n";
    for(int i = 0; i < ans; i += 1){
        cout << v[i].size();
        for(int x : v[i]) cout << " " << x;
        cout << "\n";
    }
    return 0;
}