#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m, ans = 0;
        cin >> n >> m;
        set<int> s;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            s.insert(x);
        }
        for(int i = 0, x; i < m; i += 1){
            cin >> x;
            ans += s.count(x);
        }
        cout << ans << "\n";
    }
    return 0;
}