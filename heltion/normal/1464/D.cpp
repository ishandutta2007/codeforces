#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 1000000 + 1;
int p[maxn], v[maxn];
int f(int cnt[]){
    int pans = 0;
    pans += cnt[4];
    int one = cnt[1] + cnt[4], two = cnt[2];
    pans += min(one, two);
    if(one > two) pans += (one - two) / 3 * 2;
    if(two > one) pans += two - one;
    return pans;
}
int g(int cnt[]){
    int pans = INT_MAX;
    if(cnt[2]){
        cnt[2] -= 1;
        pans = min(pans, f(cnt));
        cnt[2] += 1;
    }
    if(cnt[1] >= 2){
        cnt[1] -= 2;
        pans = min(pans, f(cnt) + 1);
        cnt[1] += 2;
    }
    if(cnt[1] >= 1 and cnt[4] >= 1){
        cnt[1] -= 1;
        cnt[4] -= 1;
        pans = min(pans, f(cnt) + 2);
        cnt[1] += 1;
        cnt[4] += 1;
    }
    if(cnt[4] >= 2){
        cnt[4] -= 2;
        pans = min(pans, f(cnt) + 3);
        cnt[4] += 2;
    }
    if(cnt[4] >= 1){
        cnt[4] -= 1;
        cnt[2] += 1;
        pans = min(pans, f(cnt) + 1);
        cnt[4] += 1;
        cnt[2] -= 1;
    }
    return pans;
}
int h(int cnt[]){
    int pans = INT_MAX;
    if(cnt[4]){
        cnt[4] -= 1;
        pans = min(pans, f(cnt));
        cnt[4] += 1;
    }
    if(cnt[1] and cnt[3]){
        cnt[1] -= 1;
        pans = min(pans, f(cnt) + 1);
        cnt[1] += 1;
    }
    if(cnt[1] >= 2){
        cnt[1] -= 2;
        pans = min(pans, g(cnt) + 1);
        cnt[1] += 2;
    }
    if(cnt[2]){
        cnt[2] -= 1;
        pans = min(pans, g(cnt));
        cnt[2] += 1;
    }
    return pans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            cin >> p[i];
            v[i] = 0;
        }
        LL ans = 1;
        if(n % 3 == 0) for(int i = 1; i <= n / 3; i += 1) ans = ans * 3 % mod;
        if(n % 3 == 1){
            ans = 4;
            for(int i = 1; i < n / 3; i += 1) ans = ans * 3 % mod;
        }
        if(n % 3 == 2){
            ans = 2;
            for(int i = 1; i <= n / 3; i += 1) ans = ans * 3 % mod;
        }
        cout << ans << " ";
        ans = 0;
        int cnt[5] = {};
        for(int i = 1; i <= n; i += 1) if(not v[i]){
            int x = i, m = 0;
            while(not v[x]){
                m += 1;
                v[x] = 1;
                x = p[x];
            }
            if(m == 1) cnt[1] += 1;
            else if(m % 3 == 1){
                ans += m / 3 - 1;
                cnt[3] += m / 3 - 1;
                cnt[4] += 1;
            }
            else if(m % 3 == 2){
                ans += m / 3;
                cnt[3] += m / 3;
                cnt[2] += 1;
            }
            else{
                ans += m / 3 - 1;
                cnt[3] += m / 3;
            }
        }
        //for(int i = 1; i <= 4; i += 1) cout << cnt[i] << " ";
        if(n % 3 == 0) ans += f(cnt);
        else if(n % 3 == 2) ans += g(cnt);
        else ans += h(cnt);
        cout << ans << "\n";
    }
    return 0;
}