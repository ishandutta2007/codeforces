#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 5000000;
double Pi = 3.1415926535897932384626;
 
//vector<ll> G[550010];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
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
 
 
//ll mod = 998244353;
ll mod = 1000000007;
 
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
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k;
ll ans;
ll x[500005], y[500005], z[500005];
P table[500005];
ll s;

void solve(){
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a >> b;
        table[i].first = a;
        table[i].second = b;
    }
    sort(table, table + n);
    for(ll i=0;i<n;i++){
        x[i] = i;
        y[i] = table[i].first - x[i];
    }
    ll idx = n - 1;
    ll deleted = 0;
    ll cost = 0;
    pqls.push(INF);
    while(1){
        if(idx > 0 && table[idx].first == table[idx-1].first){
            pqls.push(table[idx].second);
        }else{
            pqls.push(table[idx].second);
            ll norma = y[idx] - deleted;
            //pe("norma = ");p(norma);
            if(norma <= 0){
                idx--;
                if(idx == -1)break;
                continue;
            }
            while(norma--){
                ll add = pqls.top();
                //pe("add = ");p(add);
                if(add == INF){
                    assert(1 == 0);
                    return;
                }else{
                    pqls.pop();
                    cost += add;
                    deleted ++;
                }
            }
        }
        idx--;
        if(idx == -1)break;
    }
    p(cost);
    while(!pqls.empty())pqls.pop();
    return;


}
int main(){
    cin >> q;
    for(ll idx=0;idx<q;idx++){
        solve();
    }

    

    return 0;
}