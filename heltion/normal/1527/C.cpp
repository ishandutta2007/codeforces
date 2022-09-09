#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        map<int, LL> mp;
        LL ans = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            int a;
            cin >> a;
            ans += mp[a] * (n - i + 1);
            mp[a] += i;
        }
        cout << ans << "\n";
    }
	return 0;
}