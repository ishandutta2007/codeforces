#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
int n;
int cnt[50];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 26; j++) cnt[j] = 0;
        for (int j = 0; j < s.size(); j++) cnt[s[j] - 'a'] ^= 1;
        int mask = 0;
        for (int j = 0 ; j < 26; j++) mask += (1 << j) * cnt[j];
        ans += mp[mask];
        mp[mask]++;
        for (int j = 0; j < 26; j++) {
            mask ^= (1 << j);
            ans += mp[mask];
            mask ^= (1 << j);
        }
    }
    cout << ans << "\n";
    return 0;
}