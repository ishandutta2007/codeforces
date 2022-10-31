#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
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
// #define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
 
ll mod = 998244353;
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
bool multicase = true;

ll n,m,num,sum,a,b,c,d,e,h,q,p;
ll w, ans;
ll k;
ll arr[500005];
ll x, y, z;
ll dp[500005][10];

char s[500005];

ll calc(ll idx, ll type){
    if(dp[idx][type] != -1)return dp[idx][type];
    if(idx == 0){
        dp[idx][type] = 0;
        return 0;
    }
    set<ll> st;
    st.insert(max(0ll, calc(idx - x, 0)));
    if(type != 1)st.insert(max(0ll, calc(idx - y, 1)));
    if(type != 2)st.insert(max(0ll, calc(idx - z, 2)));
    for(ll i=0;i<5;i++){
        if(!st.count(i)){
            dp[idx][type] = i;
            return i;
        }
    }
    assert(0);
    return -1;
}
void solve(){
    
    cin >> n >> x >> y >> z;

    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(ll i=0;i<1000;i++){
        for(ll j=0;j<4;j++){
            dp[i][j] = -1;
        }
    }
    ll syuuki;
    if(x == 1 && y == 1 && z == 1)syuuki=2;
    if(x == 1 && y == 1 && z == 2)syuuki=3;
    if(x == 1 && y == 1 && z == 3)syuuki=4;
    if(x == 1 && y == 1 && z == 4)syuuki=5;
    if(x == 1 && y == 1 && z == 5)syuuki=6;
    if(x == 1 && y == 2 && z == 1)syuuki=3;
    if(x == 1 && y == 2 && z == 2)syuuki=3;
    if(x == 1 && y == 2 && z == 3)syuuki=4;
    if(x == 1 && y == 2 && z == 4)syuuki=5;
    if(x == 1 && y == 2 && z == 5)syuuki=6;
    if(x == 1 && y == 3 && z == 1)syuuki=4;
    if(x == 1 && y == 3 && z == 2)syuuki=4;
    if(x == 1 && y == 3 && z == 3)syuuki=2;
    if(x == 1 && y == 3 && z == 4)syuuki=7;
    if(x == 1 && y == 3 && z == 5)syuuki=2;
    if(x == 1 && y == 4 && z == 1)syuuki=5;
    if(x == 1 && y == 4 && z == 2)syuuki=5;
    if(x == 1 && y == 4 && z == 3)syuuki=7;
    if(x == 1 && y == 4 && z == 4)syuuki=5;
    if(x == 1 && y == 4 && z == 5)syuuki=3;
    if(x == 1 && y == 5 && z == 1)syuuki=6;
    if(x == 1 && y == 5 && z == 2)syuuki=6;
    if(x == 1 && y == 5 && z == 3)syuuki=2;
    if(x == 1 && y == 5 && z == 4)syuuki=3;
    if(x == 1 && y == 5 && z == 5)syuuki=2;
    if(x == 2 && y == 1 && z == 1)syuuki=3;
    if(x == 2 && y == 1 && z == 2)syuuki=3;
    if(x == 2 && y == 1 && z == 3)syuuki=4;
    if(x == 2 && y == 1 && z == 4)syuuki=5;
    if(x == 2 && y == 1 && z == 5)syuuki=6;
    if(x == 2 && y == 2 && z == 1)syuuki=3;
    if(x == 2 && y == 2 && z == 2)syuuki=4;
    if(x == 2 && y == 2 && z == 3)syuuki=5;
    if(x == 2 && y == 2 && z == 4)syuuki=6;
    if(x == 2 && y == 2 && z == 5)syuuki=7;
    if(x == 2 && y == 3 && z == 1)syuuki=4;
    if(x == 2 && y == 3 && z == 2)syuuki=5;
    if(x == 2 && y == 3 && z == 3)syuuki=5;
    if(x == 2 && y == 3 && z == 4)syuuki=6;
    if(x == 2 && y == 3 && z == 5)syuuki=7;
    if(x == 2 && y == 4 && z == 1)syuuki=5;
    if(x == 2 && y == 4 && z == 2)syuuki=6;
    if(x == 2 && y == 4 && z == 3)syuuki=6;
    if(x == 2 && y == 4 && z == 4)syuuki=6;
    if(x == 2 && y == 4 && z == 5)syuuki=7;
    if(x == 2 && y == 5 && z == 1)syuuki=6;
    if(x == 2 && y == 5 && z == 2)syuuki=7;
    if(x == 2 && y == 5 && z == 3)syuuki=7;
    if(x == 2 && y == 5 && z == 4)syuuki=7;
    if(x == 2 && y == 5 && z == 5)syuuki=7;
    if(x == 3 && y == 1 && z == 1)syuuki=2;
    if(x == 3 && y == 1 && z == 2)syuuki=4;
    if(x == 3 && y == 1 && z == 3)syuuki=4;
    if(x == 3 && y == 1 && z == 4)syuuki=5;
    if(x == 3 && y == 1 && z == 5)syuuki=6;
    if(x == 3 && y == 2 && z == 1)syuuki=4;
    if(x == 3 && y == 2 && z == 2)syuuki=5;
    if(x == 3 && y == 2 && z == 3)syuuki=5;
    if(x == 3 && y == 2 && z == 4)syuuki=6;
    if(x == 3 && y == 2 && z == 5)syuuki=7;
    if(x == 3 && y == 3 && z == 1)syuuki=4;
    if(x == 3 && y == 3 && z == 2)syuuki=5;
    if(x == 3 && y == 3 && z == 3)syuuki=6;
    if(x == 3 && y == 3 && z == 4)syuuki=7;
    if(x == 3 && y == 3 && z == 5)syuuki=8;
    if(x == 3 && y == 4 && z == 1)syuuki=5;
    if(x == 3 && y == 4 && z == 2)syuuki=6;
    if(x == 3 && y == 4 && z == 3)syuuki=7;
    if(x == 3 && y == 4 && z == 4)syuuki=7;
    if(x == 3 && y == 4 && z == 5)syuuki=8;
    if(x == 3 && y == 5 && z == 1)syuuki=6;
    if(x == 3 && y == 5 && z == 2)syuuki=7;
    if(x == 3 && y == 5 && z == 3)syuuki=8;
    if(x == 3 && y == 5 && z == 4)syuuki=8;
    if(x == 3 && y == 5 && z == 5)syuuki=8;
    if(x == 4 && y == 1 && z == 1)syuuki=5;
    if(x == 4 && y == 1 && z == 2)syuuki=3;
    if(x == 4 && y == 1 && z == 3)syuuki=5;
    if(x == 4 && y == 1 && z == 4)syuuki=5;
    if(x == 4 && y == 1 && z == 5)syuuki=6;
    if(x == 4 && y == 2 && z == 1)syuuki=3;
    if(x == 4 && y == 2 && z == 2)syuuki=6;
    if(x == 4 && y == 2 && z == 3)syuuki=6;
    if(x == 4 && y == 2 && z == 4)syuuki=6;
    if(x == 4 && y == 2 && z == 5)syuuki=7;
    if(x == 4 && y == 3 && z == 1)syuuki=5;
    if(x == 4 && y == 3 && z == 2)syuuki=6;
    if(x == 4 && y == 3 && z == 3)syuuki=7;
    if(x == 4 && y == 3 && z == 4)syuuki=7;
    if(x == 4 && y == 3 && z == 5)syuuki=8;
    if(x == 4 && y == 4 && z == 1)syuuki=5;
    if(x == 4 && y == 4 && z == 2)syuuki=6;
    if(x == 4 && y == 4 && z == 3)syuuki=7;
    if(x == 4 && y == 4 && z == 4)syuuki=8;
    if(x == 4 && y == 4 && z == 5)syuuki=9;
    if(x == 4 && y == 5 && z == 1)syuuki=6;
    if(x == 4 && y == 5 && z == 2)syuuki=7;
    if(x == 4 && y == 5 && z == 3)syuuki=8;
    if(x == 4 && y == 5 && z == 4)syuuki=9;
    if(x == 4 && y == 5 && z == 5)syuuki=9;
    if(x == 5 && y == 1 && z == 1)syuuki=2;
    if(x == 5 && y == 1 && z == 2)syuuki=3;
    if(x == 5 && y == 1 && z == 3)syuuki=2;
    if(x == 5 && y == 1 && z == 4)syuuki=6;
    if(x == 5 && y == 1 && z == 5)syuuki=6;
    if(x == 5 && y == 2 && z == 1)syuuki=3;
    if(x == 5 && y == 2 && z == 2)syuuki=7;
    if(x == 5 && y == 2 && z == 3)syuuki=7;
    if(x == 5 && y == 2 && z == 4)syuuki=7;
    if(x == 5 && y == 2 && z == 5)syuuki=7;
    if(x == 5 && y == 3 && z == 1)syuuki=2;
    if(x == 5 && y == 3 && z == 2)syuuki=7;
    if(x == 5 && y == 3 && z == 3)syuuki=8;
    if(x == 5 && y == 3 && z == 4)syuuki=8;
    if(x == 5 && y == 3 && z == 5)syuuki=8;
    if(x == 5 && y == 4 && z == 1)syuuki=6;
    if(x == 5 && y == 4 && z == 2)syuuki=7;
    if(x == 5 && y == 4 && z == 3)syuuki=8;
    if(x == 5 && y == 4 && z == 4)syuuki=9;
    if(x == 5 && y == 4 && z == 5)syuuki=9;
    if(x == 5 && y == 5 && z == 1)syuuki=6;
    if(x == 5 && y == 5 && z == 2)syuuki=7;
    if(x == 5 && y == 5 && z == 3)syuuki=8;
    if(x == 5 && y == 5 && z == 4)syuuki=9;
    if(x == 5 && y == 5 && z == 5)syuuki=10;

    for(ll i=0;i<n;i++){
        if(arr[i] > 100){
            ll dec = (arr[i] - 50) / syuuki;
            arr[i] = arr[i] - dec * syuuki;
        }
    }
    ll xorsum = 0;
    for(ll i=0;i<n;i++){
        xorsum ^= calc(arr[i], 0);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll nextxor = 0;
        nextxor = xorsum ^ calc(arr[i], 0) ^ calc(max(0ll, arr[i] - x), 0);
        if(nextxor == 0)ans ++;
        nextxor = xorsum ^ calc(arr[i], 0) ^ calc(max(0ll, arr[i] - y), 1);
        if(nextxor == 0)ans ++;
        nextxor = xorsum ^ calc(arr[i], 0) ^ calc(max(0ll, arr[i] - z), 2);
        if(nextxor == 0)ans ++;
    }
    p(ans);



    return;
}

int main(){
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        solve();
    }
    return 0;

}