#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>
#include <time.h>
#include <random>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[500005];
//vector<P> tree[500010];
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
 
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
 
 
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

 
//ll fact[800005],rfact[800005];
/*
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=800000; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[800000] = rui(fact[800000],mod - 2);
    for(ll i=800000; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}
*/
 
ll n,m,num,sum,ans,a,b,c,d,e,g,h,w,i,j,k,q;
ll x[300005],y[300005],z[300005];

ll table_size[500005];
ll table_score[500005];
ll table_final[500005];
char s[500005],t[500005];
 
bool isok;
 

ll prop_score(ll v,ll p){
    ll sum = 0;
    ll ret = table_final[p] - table_size[v] * 2 + n;
    table_final[v] = ret;
    ans = max(ans,ret);
    for(int i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        if(nv == p)continue;
        prop_score(nv,v);
    }
    return 1;
}


ll dfs_score(ll v,ll p){
    if(table_score[v]){
        return table_score[v];
    }
    ll sum = table_size[v];
    for(int i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        if(nv == p)continue;
        sum += dfs_score(nv,v);
    }
    table_score[v] = sum;
    return sum;
}



ll dfs_size(ll v,ll p){
    if(table_size[v]){
        return table_size[v];
    }
    ll sum = 1;
    for(int i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        if(nv == p)continue;
        sum += dfs_size(nv,v);
    }
    table_size[v] = sum;
    return sum;
}

int main(){
    cin >> n;
    for(i=0;i<n-1;i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    a = dfs_size(1,-1);
    ans = dfs_score(1,-1);
    table_final[1] = ans;
    for(int i=0;i<G[1].size();i++){
        ll nv = G[1][i];
        prop_score(nv,1);
    }
    for(i=1;i<=n;i++){
        //pe(i);p(table_final[i]);
    }
    p(ans);
 
    return 0;
}