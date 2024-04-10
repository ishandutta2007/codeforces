#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int cnt, int sh) {
    return cnt + sh * (cnt * (cnt - 1) / 2);    
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector <int> ans;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            ans.push_back(get(n / d, d));
            ans.push_back(get(d, n / d));
        }   
    }   

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (int e : ans) {
        cout << e << ' ';
    }   
    cout << '\n';

    return 0;
}