#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;
    sort(v.begin(), v.end());
    vector<int> w(n);
    for(int i = 0, j = 0; i < n; i += 1){
        if(2 * i + 1 < n) w[2 * i + 1] = v[i];
        else w[2 * j ++] = v[i];
    }
    int ans = 0;
    for(int i = 1; i + 1 < n; i += 1) ans += w[i - 1] > w[i] and w[i] < w[i + 1];
    cout << ans << "\n";
    for(int x : w) cout << x << " ";
    return 0;
}