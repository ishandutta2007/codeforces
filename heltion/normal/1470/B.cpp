#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
int np[maxn], p[maxn], pn, f[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[1] = 1;
    for(int i = 2; i < maxn; i += 1){
        if(not np[i]){
            p[pn ++] = i;
            f[i] = i;
        }
        for(int j = 0; j < pn; j += 1){
            int k = i * p[j];
            if(k >= maxn) break;
            np[k] = 1;
            if(f[i] % p[j] == 0) f[k] = f[i] / p[j];
            else f[k] = f[i] * p[j];
            if(i % p[j] == 0) break;
        }
    }
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            mp[f[a]] += 1;
        }
        int ans0 = 0;
        for(auto [_, x] : mp) ans0 = max(ans0, x);
        map<int, int> mp1;
        for(auto [x, y] : mp) if(y & 1) mp1[x] += y; else mp1[1] += y;
        int ans1 = 0;
        for(auto [_, x] : mp1) ans1 = max(ans1, x);
        int q;
        for(cin >> q; q; q -= 1){
            LL w;
            cin >> w;
            cout << (w ? ans1 : ans0) << "\n";
        }
    }
    return 0;
}