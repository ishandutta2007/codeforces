#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
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
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 
 
ll mod = 998244353;
 
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
ll fact[800005],rfact[800005];
 
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
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}
*/
 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];

tuple<ll, ll ,ll, ll> table[500005];

bool used[500005];
char s[500005];

void mp(ll v1, ll v2){
    num ++;
    used[v1] = true;
    used[v2] = true;
    pe(get<3>(table[v1]) + 1);
    p(get<3>(table[v2]) + 1);
    return;
}

ll next(ll v){
    for(int i = v + 1;i < n;i++){
        if(!used[i]){
            return i;
        }
    }
    //assert(1 == 0);
    return 1;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i] >> z[i];
        get<0>(table[i]) = x[i];
        get<1>(table[i]) = y[i];
        get<2>(table[i]) = z[i];
        get<3>(table[i]) = i;
    }
    sort(table,table+n);
    for(int i=0;i<n-1;i++){
        if(get<0>(table[i]) == get<0>(table[i+1]) && get<1>(table[i]) == get<1>(table[i+1])){
            mp(i, i+1);
            i += 1;
        }
    }
    for(int i=0;i<n-1;i++){
        if(num == n / 2)break;
        ll v1 = i;
        ll v2 = next(i);
        if(used[v1] || used[v2])continue;
        if(get<0>(table[v1]) == get<0>(table[v2])){
            mp(v1, v2);
        }
    }
    for(int i=0;i<n-1;i++){

        if(num == n / 2)break;
        ll v1 = i;
        if(used[v1])continue;
        ll v2 = next(i);
        if(used[v2])continue;
        mp(v1, v2);
        if(num == n / 2)break;
    }
    assert(num == n/2);

    return 0;
}