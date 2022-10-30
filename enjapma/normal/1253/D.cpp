#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
// priority_queue <P,vector<P>,greater<P> > pqps;
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
 
ll n,m,num,sum,a,b,c,d,e,h,r,l;
ll k;
ll ans;
ll x[500005], y[500005];
ll parent[500005], sizes[500005];

void init(ll n){
    for(ll i=0;i<=n;i++){
        parent[i] = i;
        sizes[i] = 1;
    }
}
ll find(ll x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = find(parent[x]);
    }
}

void unite(ll x,ll y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(sizes[x] < sizes[y])swap(x, y);

    parent[y] = x;
    sizes[x] += sizes[y];
}

bool same(ll x,ll y){
    return find(x) == find(y);
}

ll size(ll x){
    return sizes[find(x)];
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    init(n);
    for(ll i=0;i<m;i++){
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        unite(a, b);
    }
    ll ans = 0;
    ll i = 1;
    while(true){
        if(i == n + 1)break;
        vector<ll> v;
        ll max_num = i;
        if(size(i) == 1){
            i++;
            continue;
        }
        for(ll j=i+1;j<=n;j++){
            if(find(j) != find(i)){
                v.pb(j);
            }else{
                max_num = max(max_num, j);
                // unconnect
                for(ll k=0;k<v.size();k++){
                    if(find(v[k]) != find(i)){
                        unite(v[k], i);
                        ans ++;
                    }
                }
                v.clear();
                if(size(i) == j - i + 1)break;
            }
        }
        i = max_num + 1;
    }
    p(ans);


    
    return 0;
}