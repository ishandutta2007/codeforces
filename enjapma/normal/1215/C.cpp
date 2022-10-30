#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 3e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
vector<P> tree[500010];
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
 
ll n,m,num,sum,a,b,c,d,e,h,r,l,q;
ll k;
ll x[500005], y[500005], z[500005], w[500005];
char s[500005], t[500005];
bool used[500005];
bool usednew[500005];

vector<P> ans;

int main(){
    cin >> n;
    cin >> s >> t;
    for(ll i=0;i<n;i++){
        if(s[i] == t[i])continue;
        x[s[i] - 'a']++;
        y[t[i] - 'a']++;
    }
    bool dame = false;
    for(ll i=0;i<26;i++){
        if((x[i] + y[i]) % 2 == 1)dame = true;
    }
    if(dame){
        p(-1);
        return 0;
    }
    vector<T> table;
    for(ll i=0;i<n;i++){
        ll a = s[i] - 'a';
        ll b = t[i] - 'a';
        if(a == b)continue;
        table.pb(T(P(a, b), i + 1));
    }
    sort(table.begin(), table.end());
    n = table.size();
    for(ll i=0;i<n-1;i++){
        if(used[i])continue;
        if(table[i].first == table[i+1].first){
            ll idx1 = table[i].second;
            ll idx2 = table[i+1].second;
            ans.pb(P(idx1, idx2));
            used[i] = true;
            used[i+1] = true;
        }
    }
    vector<T> ban;
    for(ll i=0;i<n;i++){
        if(!used[i])ban.pb(table[i]);
    }
    ll cnt = ban.size();
    while(true){
        bool end = true;
        vector<ll> chance;
        for(ll i=0;i<ban.size();i++){
            if(ban[i].first.first != ban[i].first.second){
                end = false;
            }
        }
        if(end)break;
        bool find = false;
        for(ll i=0;i<ban.size();i++){
            for(ll j=0;j<ban.size();j++){
                if(i == j)continue;
                if(usednew[i] || usednew[j])continue;
                if(find)break;
                if(ban[i].first.first == ban[j].first.first){
                    // 
                    ans.pb(P(ban[i].second, ban[j].second));
                    find = true;
                    usednew[j] = true;
                }else if(ban[i].first.second == ban[j].first.second){
                    // 
                    ans.pb(P(ban[i].second, ban[j].second));
                    find = true;
                    usednew[i] = true;
                }
                if(find)break;
            }
            if(find)break;
        }
        if(!find){
            // 
            bool last = false;
            for(ll i=0;i<ban.size();i++){
                for(ll j=0;j<ban.size();j++){
                    if(last)break;
                    if(usednew[i] || usednew[j])continue;
                    if(ban[i].first.first == ban[j].first.second){
                        ll idx1 = ban[i].second;
                        ll idx2 = ban[j].second;
                        ans.pb(P(idx1, idx1));
                        swap(ban[i].first.first, ban[i].first.second);
                        ans.pb(P(idx1, idx2));
                        swap(ban[i].first.first, ban[j].first.second);
                        usednew[i] = true;
                        last = true;
                    }
                    if(last)break;
                }
                if(last)break;
            }
        }
    }
    p(ans.size());
    for(ll i=0;i<ans.size();i++){
        pe(ans[i].first);p(ans[i].second);
    }
    

    return 0;
}