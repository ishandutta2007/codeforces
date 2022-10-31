#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;

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
 
 
// ll mod = 998244353;
ll mod = 1000000007;
  
ll mypow(ll number1,ll number2, ll mod){
 
    if(number2 == 0){
        return 1;
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
bool multicase = false;

ll n,m,num,sum,a,b,c,d,e,h,q;
ll w, ans;
ll k;
ll x[1000005];
ll l[1000005], r[1000005];
ll rightmin[1000005];

void solve(){
    cin >> n >> m;
    for(ll i=1;i<=m;i++){
        l[i] = INF;
        r[i] = -1;
    }
    for(ll i=0;i<n;i++){
        cin >> x[i];
        l[x[i]] = min(l[x[i]], i);
        r[x[i]] = max(r[x[i]], i);
    }
    l[m+1] = INF;
    r[m+1] = INF + 10;
    rightmin[m+1] = INF;
    ll leftmost = m-1;
    ll leftmin = l[m];
    for(ll i=m;i>=1;i--){
        leftmin = min(leftmin, l[i]);
        if(r[i-1] > leftmin)break;
        leftmost --;
    }
    ll rmin = INF;
    for(ll i=m;i>=1;i--){
        rmin = min(rmin, l[i]);
        rightmin[i] = rmin;
    }
    ll right = leftmost;
    ll leftmax = -INF;
    right = max(right, 1ll);
    for(ll left=1;left<=m;left++){
        // pe(left);p(right);
        ans += m - right + 1;

        // left
        if(left > 0){
            if(l[left] < leftmax){
                right = m + 1;
                continue;
            }
        }

        leftmax = max(leftmax, r[left]);

        if(right == m+1)continue;

        // left
        while(true){
            if(r[left] > rightmin[right+1]){
                right ++;
            }else{
                break;
            }
        }

        right = max(right, left+1);
    }
    p(ans);




    return;
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
        solve();
    }
    return 0;

}