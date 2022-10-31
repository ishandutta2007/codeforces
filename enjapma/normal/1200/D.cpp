#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
vector<ll> G1[500005];
vector<ll> G2[500005];
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
 
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 
 
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
ll x[500005],y[500005],z[500005];
ll tests;
bool flag,dame;
char s[2005][2005];
ll dp[2005][2005];

void add_area(ll xi,ll xj,ll yi,ll yj){
   // pe(xi);pe(xj);pe(yi);p(yj);
    //p("!!");
    xi++;
    xj++;
    yi++;
    yj++;
    dp[xj][yj]++;
    dp[xj][yi-1]--;
    dp[xi-1][yj]--;
    dp[xi-1][yi-1]++;
}




int main(){
    cin >> n >> k;
    ll rootans = 0;
    for(i=0;i<n;i++){
        cin >> s[i];
    }
    for(i=0;i<n;i++){
        //i
        ll maxb = -1;
        ll minb = INF;
        for(j=0;j<n;j++){
            if(s[i][j] == 'B'){
                maxb = max(maxb,j);
                minb = min(minb,j);
            }
        }
        if(maxb == -1){
            rootans ++;
        }else{
            ll sa = maxb - minb;
            //p(sa);
            if(sa >= k){
               // p("continue");
                continue;
            }else{
                ll mink,maxk;
                mink = maxb - k + 1;
                maxk = min(n-k,minb);
                mink = max(0ll,mink);
                ll mina,maxa;
                mina = max(0ll,i - k + 1);
                maxa = min(n-k,i);
                add_area(mina,maxa,mink,maxk);
            }
        }
    }
    for(j=0;j<n;j++){
        ll maxb = -1;
        ll minb = INF;
        for(i=0;i<n;i++){
            if(s[i][j] == 'B'){
                maxb = max(maxb,i);
                minb = min(minb,i);
            }
        }
        if(maxb == -1){
            rootans ++;
        }else{
            ll sa = maxb - minb;
            if(sa >= k){
                continue;
            }else{
                ll mink,maxk;
                mink = maxb - k + 1;
                maxk = min(minb,n-k);
                mink = max(0ll,mink);
                ll mina,maxa;
                mina = max(0ll,j - k + 1);
                maxa = min(n-k,j);
                add_area(mink,maxk,mina,maxa);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            dp[i][j] += dp[i-1][j];
        }
    }
    for(j=1;j<=n;j++){
        for(i=0;i<=n;i++){
            dp[i][j] += dp[i][j-1];
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
           // pe(dp[i][j]);
            ans = max(ans,dp[i][j]);
        }
       //el;
    }
    p(ans + rootans);
    return 0;
}