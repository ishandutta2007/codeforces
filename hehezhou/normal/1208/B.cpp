#include <bits/stdc++.h>
using namespace std;
int n, cnt;
map<int, int> mp;
int a[2010];
int main() {
    ios :: sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++, cnt += mp[a[i]] == 2;
    int ans = 1e9;
    for(int l = 1, r = 0; l <= n;) {
        while(cnt) {
            r++;
            if(r == n + 1) break;
            mp[a[r]]--;
            cnt -= mp[a[r]] == 1;
        }
        if(r == n + 1) break;
        ans = min(ans, r - l + 1);
        mp[a[l]]++;
        cnt += mp[a[l]] == 2;
        l++;
    }
    return cout << ans << endl, 0;
}