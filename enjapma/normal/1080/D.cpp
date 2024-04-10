#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 2e18;
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

#define endl "\n"
#ifdef ENJAPMA
    #undef endl
#endif
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
const ll mod = 998244353ll;
// const ll mod = 2000000011;
  
ll mypow(ll number1,ll number2, ll mod){
    if(number2 == 0){
        return 1ll;
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
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/

bool multicase = true;

ll n,m,num,a,b,c,d,e,h,q;
ll w, k, l, r;
ll x[5005], y[5005], z[5005];

ll call(ll idx){
    if(idx > 100){
        return INF;
    }else{
        return y[idx];
    }
}

void solve(){
    cin >> n >> k;
    ll size = 2;
    for(ll i=1;i<=min(n, 100ll);i++){
        ll tmp;
        if(call(n-i) > INF / (size - 1)){
            tmp = INF;
        }else{
            tmp = call(n-i) * (size - 1);
        }
        if(tmp > INF / (size - 1)){
            tmp = INF;
        }else{
            tmp = tmp * (size - 1);
        }
        if(tmp > INF - y[i]){
            tmp = INF;
        }else{
            tmp = y[i] + tmp;
        }
        z[i] = tmp;
        if(size > INF / 2){
            size = INF;
        }else{
            size *= 2;
        }
    }
    for(ll i=1;i<=min(n, 100ll);i++){
        if(x[i] <= k && k <= z[i]){
            pe("YES");p(n - i);
            return;
        }
    }
    p("NO");
    return ;
}

int main(){
    // init();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    ll q, testcase = 1;
    ll a = 1, b = 1;
    for(ll i=1;i<=100;i++){
        if(x[i-1] > INF - a){
            x[i] = INF;
        }else{
            x[i] = x[i-1] + a;
        }
        if(y[i-1] > INF - b){
            y[i] = INF;
        }else{
            y[i] = y[i-1] + b;
        }
        if(a > INF / 2){
            a = INF;
        }else{
            a = a * 2 + 1;
        }
        if(b > INF / 4){
            b = INF;
        }else{
            b = b * 4;
        }

        // pe(x[i]);p(y[i]);
    }

    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    
    // solve();
    return 0;

}