#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
//vector<ll> G[550010];
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
 
ll n,num,sum,ans,a,b,c,d,e,g,h,w,i,j,q;
ll k[2005],m[15];
ll tests;
bool flag,dame;
ll go[4530000];
ll table[4530000];
ll ans_table[4530000];
ll ans_ref[4530000];
ll q_table[2005];
vector <ll> hukuro;
 
void dfs(ll from_v,ll q){

    ll to_v = go[from_v];

    num++;
    if(n == 1000 && (num - 1) % 252000 == 0){
        //pe(from_v / 2520);pe(from_v % 2520);
        //pe("->");
        //pe(to_v / 2520);p(to_v % 2520);
    }
    
    if(ans_ref[to_v] != -1 && ans_ref[to_v] < q){
        ll ans_num = ans_ref[to_v];
        ans = ans_table[ans_num];
        if(ans == -1 && n == 45){
            //p(ans_num);
        }
        ans_table[q] = ans;
        return;
    }
    if(table[to_v] >= 10 * q + 2){
        //hukuro
        num = 0;
        for(int k=1;k<=n;k++){
            if(q_table[k] == q){
                num++;
            }
        }
        ans_table[q] = num;
        ans = num;
        //hukuro.clear();
        return;
    }else if(table[to_v] == 10 * q + 1){
        table[to_v] ++;
        ans_ref[to_v] = q;
        //hukuro.pb(from_v);
        q_table[to_v / 2520] = q;
        dfs(to_v,q);
    }else{
        //assert(table[to_v] <= 10 * q);
        table[to_v] = 10 * q + 1;
        ans_ref[to_v] = q;
        //hukuro.pb(from_v);
        dfs(to_v,q);
    }
    return;
}
 
ll solve(ll from,ll startnum,ll q){
    //hukuro.clear();
    startnum += k[from];
    startnum %= 2520ll;
    ll from_v = from * 2520ll + startnum;

    dfs(from_v,q);

    return ans;
}
 
 /*
void add_edge(ll from,ll to,ll num){
    for(int i=0;i<2520;i++){
        ll from_v = 2520ll * from + i;

        if((i % a) == num){
            //
            ll num1 = (i + k[to]) % 2520ll;
            ll to_v = 2520ll * to + num1;
            go[from_v] = to_v;
        }
    }
}
*/

void add_edge(ll from){
    for(int i=0;i<2520;i++){
        ll from_v = 2520ll * from + i;
        ll to = m[i % a];
        ll num1 = (i + k[to]) % 2520ll;
        ll to_v = 2520ll * to + num1;
        go[from_v] = to_v;
    }
}
 
int main(){
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> k[i];
        k[i] = (k[i] % 2520ll + 2520ll) % 2520ll;
    }

    for(int i=1;i<=n;i++){
        cin >> a;
        for(int j=0;j<a;j++){
            cin >> m[j];
        }
        add_edge(i);
    }
    ll query;
    cin >> query;
    for(i=0;i<2800000;i++){
        ans_table[i] = -1;
        table[i] = -1;
        ans_ref[i] = -1;
    }
    for(i=1;i<=1000;i++){
        q_table[i] = -1;
    }
    for(int i=0;i<query;i++){
        cin >> a >> b;
        b = ((b % 2520ll) + 2520ll) % 2520ll;
       // pe("query");
       // pe(a);p(b);
        p(solve(a,b,i+1));
        //if(n == 1000)break;
       // el;
    }
 
    
    return 0;
}