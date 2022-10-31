#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 1e18;
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
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}
*/
 
ll n,m,num,sum,ans,a,b,c,e,g,h,w,i,j,k,q;
ll x[500005],y[500005],z[500005];
char s[500005];
 
ll parent[500005];
ll height[500005];
bool edge[100005];
 
void init(int n) {
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        height[i] = 0;
    }
    return;
}
 
int find(int x) {
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = find(parent[x]);
    }
}
 
bool same(int x, int y){
    return (find(x) == find(y));
}
 
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(height[x] < height[y]){
        parent[x] = y;
    }else{
        parent[y] = x;
        if(height[x] == height[y])height[x]++;
    }
}

int main(){
	cin >> n >> m;
    init(n);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        x[a] ++;
        x[b] ++;
        G[a].pb(b);
        G[b].pb(a);
    }
    ll dmin = INF;
    ll v = -1;
    for(int i=1;i<=n;i++){
        if(dmin > x[i]){
            v = i;
            dmin = x[i];
        }
    }
    for(int i=0;i<G[v].size();i++){
        ll nv = G[v][i];
        edge[nv] = true;
    }
    for(int i=1;i<=n;i++){
        if(!edge[i]){
            unite(v, i);
        }
    }
    for(int i=1;i<=n;i++){
        if(same(i, v))continue;
        ll lookv = i;
        for(int j=1;j<=n;j++){
            edge[j] = false;
        }
        for(int j=0;j<G[lookv].size();j++){
            edge[G[lookv][j]] = true;
        }
        for(int j=1;j<=n;j++){
            if(edge[j])continue;
            unite(j, lookv);
        }
    }
    for(int i=1;i<=n;i++){
        if(same(i, v))continue;
        ll lookv = i;
        for(int j=1;j<=n;j++){
            edge[j] = false;
        }
        for(int j=0;j<G[lookv].size();j++){
            edge[G[lookv][j]] = true;
        }
        for(int j=1;j<=n;j++){
            if(!edge[j])continue;
            if(!same(j, lookv)){
                unite(j, lookv);
                ans ++;
            }
        }
    }
    p(ans);

	return 0;

}