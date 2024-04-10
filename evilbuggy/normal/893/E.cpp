#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const ll mod = 1000000007;
const int maxn = 1111111;

ll f[maxn], fi[maxn];
int lpf[maxn];

ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void pre(){
    f[0] = fi[0] = 1;
    for(int i = 1; i < maxn; i++){
        f[i] = (f[i-1]*i)%mod;
        fi[i] = (fi[i-1]*modPow(i, mod-2))%mod;
    }
    memset(lpf, 0, sizeof(lpf));
    for(int i = 2; i < maxn; i++){
        if(!lpf[i]){
            for(int j = i; j < maxn; j += i){
                if(!lpf[j])lpf[j] = i;
            }
        }
    }
}

void fact(int a, vector<int> &cnt){
    while(a > 1){
        int x = lpf[a];
        int tmp = 0;
        while(a%x == 0){
            tmp++;
            a /= x;
        }
        cnt.push_back(tmp);
    }
}

inline ll ncr(int n, int r){
    return f[n]*(fi[n-r]*fi[r]%mod)%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    pre();
    int q;
    cin>>q;
    ll x, y;
    while(q--){
        cin>>x>>y;
        vector<int> cnt;
        fact(x, cnt);
        ll ans = 1;
        for(auto r : cnt){
            (ans *= ncr(y + r - 1, r)) %= mod;
        }
        (ans *= modPow(2, y-1)) %= mod;
        cout<<ans<<endl;
    }
}