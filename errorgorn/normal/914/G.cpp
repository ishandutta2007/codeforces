//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

#define vi vector<ll>
#define pii pair<ll,ll>
void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			ll &u = a[j], &v = a[j + step]; tie(u, v) =
				inv ? pii(fix(v - u), u) : pii(v, fix(u + v)); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				// pii(u + v, u - v);                   // XOR /// include-line
		}
	}
	// if (inv) for (int& x : a) x /= sz(a); // XOR only /// include-line
}
vi conv(vi a, vi b) {
	FST(a, 0); FST(b, 0);
	rep(i,0,sz(a)) a[i] = fix(a[i]*b[i]);
	FST(a, 1); 
	rep(x,0,sz(a)) a[x]%=MOD;
	return a;
}

void FST2(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			ll &u = a[j], &v = a[j + step]; tie(u, v) =
				//inv ? pii(v - u, u) : pii(v, u + v); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				pii(fix(u + v), fix(u - v));                   // XOR /// include-line
		}
	}
	ll temp=qexp(sz(a),MOD-2,MOD);
	if (inv) for (ll& x : a) x=fix(x*temp); // XOR only /// include-line
}
vi conv2(vi a, vi b) {
	FST2(a, 0); FST2(b, 0);
	rep(i,0,sz(a)) a[i] = fix(a[i]*b[i]);
	FST2(a, 1); 
	rep(x,0,sz(a)) a[x]%=MOD;
	return a;
}

int n;
int arr[1000005];

int acnt[140000];
int bcnt[140000];

const int B=17;
ll ahat[18][140000];
ll bhat[18][140000];
ll hat[18][140000];
ll conv_ans[140000];

ll fib[140000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fib[0]=0,fib[1]=1;
	rep(x,2,140000) fib[x]=(fib[x-1]+fib[x-2])%MOD;
	
	cin>>n;
	rep(x,0,n){
		cin>>arr[x];
		acnt[arr[x]]++;
		bcnt[arr[x]]++;
	}
	
	rep(x,0,1<<B){
		ahat[__builtin_popcount(x)][x]=acnt[x];
		bhat[__builtin_popcount(x)][x]=bcnt[x];
	}
	
	rep(cnt,0,B+1){
		rep(bit,0,B){
			rep(x,0,1<<B) if (x&(1<<bit)){
				ahat[cnt][x]+=ahat[cnt][x^(1<<bit)];
				bhat[cnt][x]+=bhat[cnt][x^(1<<bit)];
			}
		}
	}
	
	rep(cnt,0,B+1){
		rep(cnt2,0,cnt+1){
			rep(x,0,1<<B){
				hat[cnt][x]+=ahat[cnt2][x]*bhat[cnt-cnt2][x];
			}
		}
	}
	
	rep(cnt,0,B+1){
		rep(bit,0,B){
			rep(x,0,1<<B) if (x&(1<<bit)){
				hat[cnt][x]-=hat[cnt][x^(1<<bit)];
			}
		}
	}
	
	rep(x,0,1<<B) conv_ans[x]=hat[__builtin_popcount(x)][x];

	//rep(x,0,1<<B) cout<<conv_ans[x]<<" "; cout<<endl;
	
	vector<ll> v1;
	rep(x,0,1<<B) v1.push_back(conv_ans[x]%MOD*fib[x]%MOD);
	
	vector<ll> temp;
	rep(x,0,1<<B) temp.push_back(acnt[x]);
	temp=conv2(temp,temp);
	
	//rep(x,0,1<<B) cout<<temp[x]<<" "; cout<<endl;
	
	vector<ll> v2;
	rep(x,0,1<<B) v2.push_back(temp[x]*fib[x]%MOD);
	
	vector<ll> v3;
	rep(x,0,1<<B) v3.push_back(acnt[x]*fib[x]%MOD);
	
	temp=conv(v1,conv(v2,v3));
	
	//rep(x,0,1<<B) cout<<temp[x]<<" "; cout<<endl;
	
	ll ans=0;
	rep(x,0,B){
		ans+=temp[1<<x];
	}
	
	cout<<ans%MOD<<endl;
}