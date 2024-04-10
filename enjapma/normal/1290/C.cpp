#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e17;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;

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
// #define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
 
ll mod = 998244353;
//ll mod = 1000000007;
 
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

ll n,m,num,sum,a,b,c,d,e,h,r,l,q;
ll k;
ll x[500005], y[500005], z[500005];
char s[500005];
vector<ll> R[700005];


void check(){
    return;
}

void query(){

    return;
}

void input(){

    return;
}

ll parent[800005], sizes[800005];
ll t_sizes[800005];

void init(ll n){
    for(ll i=0;i<=2*n+10;i++){
        parent[i] = i;
    }
    for(ll i=1;i<=n;i++){
        t_sizes[i] = 1;
    }
    for(ll i=1;i<=2*n+10;i++){
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
    // pe("unite");pe(x);p(y);
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(sizes[x] < sizes[y])swap(x, y);

    parent[y] = x;
    t_sizes[x] += t_sizes[y];
    sizes[x] += sizes[y];
}

bool same(ll x,ll y){
    return find(x) == find(y);
}

ll size(ll x){
    return t_sizes[find(x)];
}

int main(){
    cin >> n >> k;
    cin >> s;
    init(k);
    for(ll i=0;i<k;i++){
        cin >> q;
        for(ll j=0;j<q;j++){
            cin >> a;
            R[a].pb(i+1);
        }
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        // i1

        ll truth = find(0);

        if(s[i] == '0'){
            if(R[i+1].size() == 1){
                if(find(R[i+1][0]) == truth){

                }else{
                    ll before = min(size(R[i+1][0]), size(R[i+1][0] + k));
                    ll after = size(R[i+1][0]);
                    unite(R[i+1][0], 0);
                    ans += after - before;
                }
            }else if(R[i+1].size() == 2){
                ll a = R[i+1][0], b = R[i+1][1];
                ll before = 0;
                ll after = 0;
                if(same(a, b + k) || same(a + k, b)){

                }else if(same(a, 0)){
                    before = min(size(b), size(b + k));
                    after = size(b + k);
                }else if(same(b, 0)){
                    before = min(size(a), size(a + k));
                    after = size(a + k);
                }else if(same(a + k, 0)){
                    before = min(size(b), size(b + k));
                    after = size(b);
                }else if(same(b + k, 0)){
                    before = min(size(a), size(a + k));
                    after = size(a);
                }else{
                    before = min(size(a), size(a + k)) + min(size(b), size(b + k));
                    after = min(size(a) + size(b + k), size(a + k) + size(b));
                }
                unite(a, b + k);
                unite(a + k, b);
                ans += after - before;
            }
        }else{
            if(R[i+1].size() == 1){
                if(same(R[i+1][0] + k, 0)){

                }else{
                    ll before = min(size(R[i+1][0]), size(R[i+1][0] + k));
                    ll after = size(R[i+1][0] + k);
                    unite(R[i+1][0] + k, 0);
                    ans += after - before;
                }
            }else if(R[i+1].size() == 2){
                ll a = R[i+1][0], b = R[i+1][1];
                
                ll before = 0;
                ll after = 0;
                if(same(a, b) || same(a + k, b + k)){

                }else if(same(a, 0)){
                    before = min(size(b), size(b + k));
                    after = size(b);
                }else if(same(b, 0)){
                    before = min(size(a), size(a + k));
                    after = size(a);
                }else if(same(a + k, 0)){
                    before = min(size(b), size(b + k));
                    after = size(b + k);
                }else if(same(b + k, 0)){
                    before = min(size(a), size(a + k));
                    after = size(a + k);
                }else{
                    before = min(size(a), size(a + k)) + min(size(b), size(b + k));
                    after = min(size(a) + size(b), size(a + k) + size(b + k));
                }
                unite(a, b);
                unite(a + k, b + k);
                ans += after - before;
            }
        }
        p(ans);
    }
    return 0;
}