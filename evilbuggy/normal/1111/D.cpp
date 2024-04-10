#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;

const ll mod = 1000000007;
const int maxn = 100005;
const int maxk = 52;

ll dp[maxn], dp2[maxn], ways[maxk][maxk], CNST;
int f[maxk];

inline int get(char ch){
    if(ch >= 'a' && ch <= 'z')return ch - 'a';
    return ch - 'A' + 26;
}

inline void add(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

inline void sub(ll &a, ll b){
    a -= b;
    if(a < 0)a += mod;
}

void add(int x){
    for(int i = 0; i < maxn; i++){
        dp2[i] = dp[i];
        if(i >= x)add(dp2[i], dp[i-x]);
    }
    for(int i = 0; i < maxn; i++){
        dp[i] = dp2[i];
    }
}

void sub(int x){
    for(int i = 0; i < maxn; i++){
        dp[i] = dp2[i];
    }
    for(int i = x; i < maxn; i++){
        sub(dp2[i], dp2[i - x]);
    }
    for(int i = 0; i < maxn; i++){
        dp[i] = dp2[i];
    }
}

ll fact(int n){
    ll ret = 1;
    for(int i = 2; i <= n; i++){
        (ret *= i) %= mod;
    }
    return ret;
}

ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void comp(int n){
    CNST = (fact(n/2)*fact(n/2))%mod;
    ll den = 1;
    for(int i = 0; i < 52; i++){
        (den *= fact(f[i])) %= mod;
    }
    (CNST *= modPow(den, mod - 2)) %= mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);
    
    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        f[get(s[i])]++;
    }
    comp(n);
    dp[0] = 1;
    for(int i = 0; i < maxk; i++){
        if(f[i])add(f[i]);
    }
    for(int i = 0; i < maxk; i++){
        for(int j = i; j < maxk; j++){
            if(!f[i] || !f[j])continue;
            if(i == j){
                sub(f[i]);
                ways[i][j] = (2*CNST*dp[n/2])%mod;
                
                add(f[i]);
            }else{
                sub(f[i]);
                sub(f[j]);
                ways[i][j] = ways[j][i] = (2*CNST*dp[n/2])%mod;
                
                add(f[i]);
                add(f[j]);
            }
        }
    }
    int q, x, y;
    cin>>q;
    while(q--){
        cin>>x>>y;
        x--; y--;
        cout<<ways[get(s[x])][get(s[y])]<<'\n';
    }
}