#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;
const ll Mod = 1e9 + 7;

ll inv(ll a) {
    ll e = Mod - 2, ret = 1;
    while(e) {
        if(e & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        e >>= 1;
    } 
    return ret;
}

int n;
ll a[14];
ll dp[1<<14];
ll mul[1<<14];
ll sum[14];

int main() {
    fast;

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    mul[0] = 1;
    for(int i=1; i<(1<<n); i++) {
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                sum[j] = 1;
                for(int k=0; k<n; k++) {
                    if((i & (1<<k)) && k != j) {
                        sum[j] *= a[j] * inv(a[j] + a[k]) % Mod;
                        sum[j] %= Mod;
                    }
                }   
            }
        }

        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                mul[i] = mul[i ^ (1<<j)];
                for(int k=0; k<n; k++) {
                    if((i & (1<<k)) && k != j) {
                        mul[i] *= a[j] * inv(a[j] + a[k]) % Mod;
                        mul[i] %= Mod;
                        mul[i] *= a[k] * inv(a[j] + a[k]) % Mod;
                        mul[i] %= Mod;
                    }
                }  
                break;
            }
        }

        dp[i] = 1;
        for(int j=(i-1) & i; j; j = (j-1) & i) {
            ll tot = 1;
            for(int k=0; k<n; k++) {
                if(j & (1<<k)) {
                    tot *= sum[k];
                    tot %= Mod;
                }
            }

            tot = tot * inv(mul[j]) % Mod;
            tot = tot * dp[j] % Mod;

            dp[i] += Mod - tot;
            dp[i] %= Mod;
        }
    }

    for(int j=0; j<n; j++) {
        sum[j] = 1;
        for(int k=0; k<n; k++) {
            if(k != j) {
                sum[j] *= a[j] * inv(a[j] + a[k]) % Mod;
                sum[j] %= Mod;
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<(1<<n); i++) {
        ll tot = 1;
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(i & (1<<j)) {
                cnt++;
                tot *= sum[j];
                tot %= Mod;
            }
        }

        tot = tot * inv(mul[i]) % Mod;
        tot = tot * dp[i] % Mod;

        ans += tot * cnt % Mod;
        ans %= Mod;
    }

    cout << ans;
}