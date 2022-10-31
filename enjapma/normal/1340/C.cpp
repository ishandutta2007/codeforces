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

bool multicase = false;

ll n,m,num,a,b,c,d,e,h,q;
ll w, k;
ll x[500005];
ll cost[15000007];

const ll offset = 1001;

void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x[i];
    }
    sort(x, x + m);
    ll r, g;
    cin >> g >> r;
    for(int i=0;i<offset*m+r+offset;i++){
        cost[i] = INF;
    }
    deque<P> dq;
    cost[g] = 0;
    dq.push_front(P(0, g));
    ll mini = INF;
    while(!dq.empty()){
        P p = dq.front();
        dq.pop_front();
        ll nowcost = p.first;
        ll v = p.second;
        if (nowcost > mini + 2)break;
        if (nowcost > cost[v]) continue;
        ll idx = v / offset, remain = v % offset;
        if(remain == 0){
            ll nv = idx * offset + g;
            ll newcost = cost[v] + 1;
            if (cost[nv] > newcost) {
                cost[nv] = newcost;
                dq.push_back(P(newcost, nv));
            }
        }else{
            for(int j=idx-1;j<=idx+1;j+=2){
                if(j < 0)continue;
                if(m <= j)continue;
                ll dis = abs(x[idx] - x[j]);
                if(dis > remain)continue;
                ll nv = j * offset + remain - abs(x[idx] - x[j]);
                if (cost[nv] > cost[v]){
                    if(j == m - 1)mini = min(mini, cost[v]);
                    cost[nv] = cost[v];
                    dq.push_front(P(cost[v], nv));
                }
            }
        }
    }
    ll ans = INF;
    for(ll i=0;i<=g;i++){
        ll v = (m - 1) * offset + i;
        if(cost[v] >= INF / 2)continue;
        ll res = cost[v] * r + + cost[v] * g + g - i;
        ans = min(ans, res);
    }
    if(ans == INF){
        p(-1);
        return;
    }
    p(ans);
    return;
}

int main(){
    // init();
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