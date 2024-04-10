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
#define el cout<<endl;
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
ll sum[200005], pi[200005];
ll x[500005];
string s;
ll idx = 0;
vector<P> v;

bool overflow(ll a, ll b){
    ll idx = 0;
    while(a >= 10){
        a /= 10;
        idx ++;
    }
    while(b >= 10){
        b /= 10;
        idx ++;
    }
    if(idx >= 13){
        return true;
    }else if(idx == 12 && a * b > 10){
        return true;
    }else{
        return false;
    }
}
void solve(){
    cin >> n >> k;

    for(ll i=0;i<n;i++){
        cin >> x[i];
        if(v.empty() || v.back().first != 1 || x[i] != 1){
            v.pb(P(x[i], 1));
        }else{
            v.back().second ++;
        }
    }
    ll m = v.size();
    ll ans = 0;
    for(ll i=0;i<m;i++){
        // pe("start at ");p(i);
        ll l = i;
        ll left, rightmax, rightmin;
        if(v[i].first != 1){
            left = v[i].first;
            rightmax = rightmin = k * v[i].first;
            if(left == rightmax)ans ++;
        }else{
            left = v[i].first;
            rightmax = k * v[i].second;
            rightmin = k;
            if(k == 1){
                ans += v[i].second;
            }
        }
        for(ll j=i+1;j<m;j++){
            if(v[j].first != 1){
                left *= v[j].first;
                rightmax += k * v[j].first;
                rightmin += k * v[j].first;
                if(overflow(left, v[j].first)){
                    break;
                }else if(rightmin <= left && left <= rightmax && (rightmax - left) % k == 0){
                    ans ++;
                }
            }else{
                ll timesmin = (left - rightmax + k - 1) / k;
                ll timesmax = (left - rightmin) / k;
                timesmin = max(1ll, timesmin);
                timesmax = min(v[j].second, timesmax);
                if(timesmax - timesmin >= 0 && abs(rightmax - left) % k == 0)ans += timesmax - timesmin + 1;
                rightmin += k * v[j].second;
                rightmax += k * v[j].second;
            }
            // pe(ans)pe(left);pe(rightmax);p(rightmin);

        }
        // p(ans);
    }
    p(ans);

    return;
}

int main(){
    // init();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
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
    
    // while(solve());
    // solve();
    return 0;

}