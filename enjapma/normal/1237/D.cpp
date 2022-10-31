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
bool used[500005];
char s[500005];

struct SegmentTree {
    //SegmentTree seg( vector<ll>(l + 5, INF) );
private:
    ll n;
    vector<ll> node;
 
public:
    SegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }
 
    void update(ll x, ll val) {
    //a[x]y()
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
 
    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
    //[a,b)
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};


void muri(){
    for(int i=0;i<n;i++){
        pe(-1);
    }
    el;
    return;
}
int main(){
    cin >> n;
    SegmentTree seg( vector<ll>(3 * n + 5, 0) );
    ll large = 0;
    ll small = INF;
    for(int i=0;i<n;i++){
        cin >> x[i];
        large = max(large,x[i]);
        small = min(small,x[i]);
        seg.update(i, x[i]);
    }
    if(large <= small * 2){
        muri();
        return 0;
    }
    for(int i=0;i<n;i++){
        x[i + n] = x[i];
        seg.update(i + n, x[i]);
    }
    for(int i=0;i<n;i++){
        x[i + 2 * n] = x[i];
        seg.update(i + 2 * n,x[i]);
    }
    ll right = 0;
    
    for(int left = 0;left < n;left++){
        while(right < 3 * n && (seg.getmax(left, right + 2) <= 2 * x[right + 1])){
            right ++;
        }
        pe(right - left + 1);

        if(right == left)right ++;
    }
    el;



    return 0;
}