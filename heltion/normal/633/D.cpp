#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
constexpr int inf = 1'000'000'000;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i += 1){
        cin >> a[i];
        mp[a[i]] += 1;
    }
    int ans = max(mp[0], 2);
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1)
            if(i != j and (a[i] or a[j])){
                map<int, int> cnt;
                int x = a[i], y = a[j], m = 2;
                cnt[x] += 1;
                cnt[y] += 1;
                while(true){
                    int z = x + y;
                    if(abs(z) > inf) break;
                    if(not mp.count(z)) break;
                    if(cnt[z] == mp[z]) break;
                    cnt[z] += 1;
                    x = y;
                    y = z;
                    ans = max(ans, m += 1);
                }
            }
    cout << ans;
    return 0;
}