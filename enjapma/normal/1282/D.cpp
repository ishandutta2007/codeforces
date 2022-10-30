#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 1e18;
const ll fact_table = 5000000;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
vector<ll> R[550010];
vector<pair<ll, double> > tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//,,,
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<"\n";
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
 
ll n,m,num,sum,a,b,c,d,e,f,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
ll cnt[500005];
bool used[500005];

int main(){
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    
    p("a");
    ll ans1, ans2;
    cin >> ans1;
    if(ans1 == 0){
        return 0;
    }
    if(ans1 == 300){
        for(ll j=0;j<300;j++){
            pu("b");
        }
        el;
        cin >> ans;
        return 0;
    }
    for(ll i=0;i<ans1+1;i++){
        pu("a");
    }
    el;
    cin >> ans2;
    if(ans2 == 0){
        return 0;
    }
    if(ans2 == ans1 + 1){
        for(ll i=0;i<ans2 - 1;i++){
            pu("b");
        }
        el;
        cin >> ans2;
        for(ll i=0;i<ans2;i++){
            pu("b");
        }
        el;
        cin >> ans1;
        return 0;
    }

    ll n = ans1 + 1;
    //cin >> ans;
    ll beforeans = ans2;
    //p(beforeans);
    for(ll i=0;i<n;i++){
        if(i >= 0)used[i] = true;
        for(ll j=0;j<n;j++){
            if(used[j]){
                pu("b");
            }else{
                pu("a");
            }
        }       
        el;
        cin >> ans;
        if(ans == 0){
            return 0;
        }else if(beforeans > ans){

        }else{
            if(i >= 0)used[i] = false;
        }
        beforeans = ans;
    }


    
    
    return 0;
}