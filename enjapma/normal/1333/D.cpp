#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
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
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<"\n";
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
// const ll mod = 998244353ll;
const ll mod = 2000000011;
  
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
    rfact[fact_table] = rui(fact[fact_table],mod - 2);
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
ll w, k, l, r;
ll x[500005], y[500005], z[500005];
string s;
vector<ll> u;
vector<ll> print;

void solve(){
    cin >> n >> k;
    cin >> s;
    vector<vector<ll>> v;
    ll mini = 0, maxi = 0;
    while(true){
        bool find = false;
        u.clear();
        for(ll i=0;i<n-1;i++){
            if(s[i] == 'R' && s[i+1] == 'L'){
                find = true;
                u.pb(i+1);
            }
        }
        for(ll i=0;i<u.size();i++){
            s[u[i]-1] = 'L';
            s[u[i]] = 'R';
            maxi ++;
        }
        if(!find)break;
        v.pb(u);
    }
    mini = v.size();
    if(k < mini || maxi < k){
        p(-1);
        return;
    }
    ll hand = k;
    for(ll i=0;i<v.size();i++){
        while(true){
            print.clear();
            ll remain = v.size() - i;
            if(hand == remain){
                // push
                hand--;
                print = v[i];
                v[i].clear();
            }else{
                // 1push
                print.pb(v[i].back());
                v[i].pop_back();
                hand--;
            }
            pe(print.size());
            for(ll k=0;k<print.size();k++){
                pe(print[k]);
            }
            el;
            if(v[i].size() == 0)break;
        }
    }


    return ;
}

int main(){
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll q;
    if(multicase){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
    }
    
    // solve();
    return 0;

}