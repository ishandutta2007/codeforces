#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e13;
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

ll calc(ll x1, ll x2, ll y1, ll y2){
    if(x2 < x1 || y2 < y1)return 0;
    bool flag = (x1 + y1) % 2 == 0;
    ll res = (x2 - x1 + 1) * (y2 - y1 + 1);
    ll w, b;
    if(res % 2 == 1 && flag){
        w = (res + 1) / 2;
        b = res / 2;
    }else{
        w = res / 2;
        b = (res + 1) / 2;
    }
    return w;
}

void solve(){
    cin >> n >> m;
    ll x11, x22, y11, y22, x33, x44, y33, y44;
    cin >> x11 >> y11 >> x22 >> y22 >> x33 >> y33 >> x44 >> y44;
    ll x55 = max(x11, x33);
    ll y55 = max(y11, y33);
    ll x66 = min(x22, x44);
    ll y66 = min(y22, y44);
    ll w = calc(1, n, 1, m) - calc(x11, x22, y11, y22) + (x22 - x11 + 1) * (y22 - y11 + 1)
            + calc(x55, x66, y55, y66) - calc(x33, x44, y33, y44);
    if(x55 <= x66 && y55 <= y66)w -= (x66 - x55 + 1) * (y66 - y55 + 1);
    ll all = n * m;
    pe(w);p(all - w);

    return ;
}

int main(){
    // init();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    ll q, testcase = 1;
    

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