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
ll x[500005], y[500005], z[500005];
bool used[500005];
string s, t;

vector<ll> G[500005];

ll dfs(ll v){
    used[v] = true;
    ll nv = G[v][0];
    if(used[nv]){
        return 1ll;
    }else{
        return 1 + dfs(nv);
    }
}

void solve(){
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> x[i];
        G[i].clear();
        G[i].pb(x[i]);
        used[i] = false;
    }
    for(ll i=1;i<=n;i++){
        cin >> y[i];
    }
    ll ans = INF;
    vector<ll> v, cand;
    for(ll i=1;i<=n;i++){
        if(used[i])continue;
        ll size = dfs(i);
        v.clear();
        ll u = i;
        ll tmp = size;
        while(tmp--){
            v.pb(u);
            u = x[u];
        }
        ans = min(ans, size);
        cand.clear();
        for(ll j=1;j*j<=size;j++){
            if(size % j != 0)continue;

            cand.pb(j);
            if(j != 1)cand.pb(size / j);
        }

        for(ll j=0;j<cand.size();j++){

            ll move = cand[j];
            if(ans < move)continue;

            for(ll u=0;u<move;u++){
                bool dame = false;
                for(ll i=u;i+move<size;i+=move){
                    if(y[v[i]] != y[v[i+move]]){
                        dame = true;
                        break;
                    }
                }
                if(!dame){
                    ans = min(ans, move);
                }
            }
            
        }
    }
    p(ans);


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
    return 0;

}