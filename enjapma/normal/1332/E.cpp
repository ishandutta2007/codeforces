#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 1200008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//,,,
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
 
ll mod = 998244353ll;
// ll mod = 1000000007;
  
ll mypow(ll number1,ll number2, ll mod){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = mypow(number1,number2 / 2, mod);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
 
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
 
/*
ll fact[fact_table + 5],rfact[fact_table + 5]; 
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[fact_table] = rui(fact[fact_table],mod - 2);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/
bool multicase = false;

ll n,m,num,sum,a,b,c,d,e,h,q;
ll w, k, l, r;
ll x[500005], y[500005], z[500005];

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// 
ll m_size = 2;

vec matmul(vec &dp, mat &mt){
    vec ret(m_size, 0ll);
    for(ll i=0;i<m_size;i++){
        for(ll j=0;j<m_size;j++){
            ret[i] += (mt[i][j] * dp[j]) % mod;
            ret[i] %= mod;
        }
    }
    return ret;
}
mat update(mat &mt){
    mat ret(m_size, vec(m_size, 0ll));
    for(ll i=0;i<m_size;i++){
        for(ll j=0;j<m_size;j++){
            for(ll k=0;k<m_size;k++){
                ret[i][j] += (mt[i][k] * mt[k][j]) % mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

void matpow(vec &dp, mat &mt, ll k){
    ll m = dp.size();
    while(k){
        if(k&1)dp = matmul(dp, mt);
        mt = update(mt);
        k /= 2;
    }
    return;
}


void solve(){
    cin >> n >> m >> l >> r;
    if(n % 2 == 0 || m % 2 == 0){
        vec dp(2);
        dp[0] = 1, dp[1] = 0;
        mat mt(2, vec(2));
        ll one = 0, zero = 0;
        zero = r / 2 - (l - 1) / 2;
        one = r - l + 1 - zero;
        one %= mod;
        zero %= mod;
        mt[0][0] = zero; mt[0][1] = one; mt[1][0] = one; mt[1][1] = zero;
        matpow(dp, mt, n * m);

        ll ans = dp[0];
        ans %= mod;
        p(ans); 
    }else{
        ll ans = rui(r - l + 1, n * m);
        p(ans);
    }
    
    return;
}

int main(){
    // init();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    ll q;
    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        solve();
    }
    
    // while(solve());
    // solve();
    return 0;

}