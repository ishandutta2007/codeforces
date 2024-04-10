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
 
// const ll mod = 998244353ll;
const ll mod = 1000000007ll;
  
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
ll x[500005], y[500005], z[500005];
vector<ll> G[500005];
ll ans;
vector<P> v;

void call(ll a, ll b, ll c){
    if(c == INF || c == -INF)return;
    ll res = (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
    ans = min(ans, res);
    return;
}

void calc(ll a, ll b, ll idx){
    if(a == -INF || b == -INF)return;
    if(a == INF || b == INF)return;
    ll m = G[idx].size();
    ll ng = -1, ok = m - 1;
    ll mid;
    while(ok - ng > 1){
        mid = (ok + ng) / 2;
        if(G[idx][mid] * 2 <= a + b && G[idx][mid + 1] * 2 <= a + b){
            ng = mid;
        }else if(G[idx][mid] * 2 > a + b && G[idx][mid + 1] * 2 > a + b){
            ok = mid;
        }else{
            break;
        }
    }
    call(a, b, G[idx][mid]);
    call(a, b, G[idx][mid + 1]);
    return;
}

void solve(){
    cin >> a >> b >> c;
    ans = INF;
    v.clear();
    for(ll i=1;i<=3;i++){
        G[i].clear();
    }
    for(ll i=0;i<a;i++){
        cin >> d;
        v.pb(P(d, 1));
        G[1].pb(d);
    }
    for(ll i=0;i<b;i++){
        cin >> d;
        v.pb(P(d, 2));
        G[2].pb(d);
    }
    for(ll i=0;i<c;i++){
        cin >> d;
        v.pb(P(d, 3));
        G[3].pb(d);
    }
    sort(v.begin(), v.end());
    for(ll i=1;i<=3;i++){
        G[i].pb(-INF), G[i].pb(INF);
        sort(G[i].begin(), G[i].end());
    }
    ll la = -INF, lb = -INF, lc = -INF;
    for(ll i=0;i<v.size();i++){
        P take = v[i];
        if(take.second == 1){
            la = take.first;
            calc(la, lc, 2);
            calc(la, lb, 3);
        }else if(take.second == 2){
            lb = take.first;
            calc(la, lb, 3);
            calc(lc, lb, 1);
        }else{
            lc = take.first;
            calc(lc, la, 2);
            calc(lc, lb, 1);
        }
    }
    p(ans);
    return;
}


int main(){
    // init();
    // 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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