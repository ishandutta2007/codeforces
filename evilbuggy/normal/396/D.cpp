#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;
const int maxn = 1000005;

ll fac[maxn], mem[maxn];

void pre(){
    fac[0] = fac[1] = 1;
    mem[0] = mem[1] = 0;
    for(int i = 2; i < maxn; i++){
        fac[i] = (fac[i-1]*i)%mod;
        mem[i] = ((1LL*i*(i-1)/2%mod)*fac[i-1] + i*mem[i-1])%mod;
    }
}

inline ll h(int l, int n){
    ll ret = 1LL*l*(l-1)/2%mod;
    (ret *= fac[n-1]) %= mod;
    ret += (l*mem[n-1])%mod;
    return ret%mod;
}

int p[maxn], f[maxn];

void update(int i, int n, int x){
    while(i <= n){
        f[i] += x;
        i += i&(-i);
    }
}

int query(int i){
    int ans = 0;
    while(i > 0){
        ans += f[i];
        i &= (i - 1);
    }
    return ans;
}

int main(){
    pre();
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }
    memset(f, 0, sizeof(f));
    ll ans = 0, permcount = 1;
    for(int i = n; i >= 1; i--){
        int cnt = query(p[i] - 1);
        ll tmp = h(cnt, n-i+1);
        (tmp += permcount*cnt) %= mod;
        (ans += tmp) %= mod;
        (permcount += cnt*fac[n-i]) %= mod;
        update(p[i], n, 1);
//         cout<<permcount<<" "<<cnt<<" "<<i<<endl;
    }
    cout<<ans<<endl;
}