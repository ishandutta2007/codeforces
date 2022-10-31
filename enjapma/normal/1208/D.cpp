#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 1e15;
const ll fact_table = 5000000;
double Pi = 3.1415926535897932384626;
 
//vector<ll> G[550010];
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
 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
char s[500005];
ll table[2005][2005];

struct LazySegmentTree {
private:
    ll n;
    vector<P> node;
    vector<ll> lazy;
    vector<bool> lazyFlag;
 
public:
    LazySegmentTree(vector<ll> v) {
        ll sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);
 
        for(int i=0; i<sz; i++) node[i+n-1] = P(v[i],i);
        for(int i=n-2; i>=0; i--) {
            if(node[i*2+1].first == node[i*2+2].first){
                node[i] = max(node[i*2+1], node[i*2+2]);
            }else{
                node[i] = min(node[i*2+1], node[i*2+2]);
            }
        }
    }
 
    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k].first += lazy[k];
            if(r - l > 1) {
                lazy[k*2+1] += lazy[k];
                lazy[k*2+2] += lazy[k];
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazy[k] = 0;
            lazyFlag[k] = false;
        }
    }
 
    void update(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            int vl = 2 * k + 1, vr = 2*k+2;
            if(node[vl].first == node[vr].first){
                node[k] = max(node[vl], node[vr]);
            }else{
                node[k] = min(node[vl], node[vr]);
            }
        }
    }
    P find(int a,int b,int k=0,int l=0,int r=-1){
        if(r < 0)r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return P(INF, -1);
        if(a <= l && r <= b) return node[k];
        int mid = (l + r) / 2;
        P vl = find(a, b, 2*k+1, l, mid);
        P vr = find(a, b, 2*k+2, mid, r);
        if(vl.first == vr.first){
            return max(vl, vr);
        }else{
            return min(vl, vr);
        }
    }

};
 
int main(){
	cin >> n;
	vector<ll> v;
	for(int i=0;i<n;i++){
		cin >> x[i];
		v.pb(x[i]);
	}
	LazySegmentTree seg( v );
	num = 1;
	for(int i=0;i<n;i++){

        P p = seg.find(0, n);
        ll idx = p.second;
		x[idx] = num++;

		seg.update(idx, idx + 1, INF);

		seg.update(idx + 1, n, -(num-1));

	}
	for(int i=0;i<n;i++){
		pe(x[i]);
	}
	el;

    return 0;
}