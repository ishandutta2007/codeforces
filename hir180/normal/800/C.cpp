#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
bool used[200005];
vector<int>D;
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%m;
		x=x*x%m;
		n>>=1;
	}
	return res;
}
vector<int>num[2005];
int dp[2005],nxt[2005];
int rec(int id){
	if(dp[id] >= 0) return dp[id];
	int ret,mx=-1,idd=-1;
	ret = num[id].size();
	for(int i=id+1;i<D.size();i++){
		if(D[i] % D[id] == 0){
			if(mx < rec(i)){
				mx = rec(i);
				idd = i;
			}
		}
	}
	dp[id] = ret+mx;
	nxt[id] = idd;
	return dp[id];
}
int eu;
bool u[200005];
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0) return a;
	else return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll g = a; x = 1; y = 0;
	if(b != 0) g = extgcd(b,a%b,y,x),y-=(a/b)*x;
	return g;
}
ll AxB(ll A,ll B,ll C){
	//minimum non-negaitive x such that Ax godo b (mod C)
	if(B%gcd(A,C) != 0) return -1;
	ll x,y;
	extgcd(A,C,x,y);
	x = x*B/gcd(A,C)%(C/gcd(A,C));
	ll f = C/gcd(A,C);
	if(x > 0){
		x %= abs(f);
	}
	else{
		x = (x%abs(f)+abs(f))%abs(f);
	}
	return x;
}
vector<int>rev(vector<int>a){
	vector<int>ret;
	ret.pb(a[0]);
	for(int i=1;i<a.size();i++){
		ll r = AxB(1LL*a[i-1],1LL*a[i],1LL*m);
		r = (r%m+m)%m;
		assert(1LL*a[i-1]*r%m == 1LL*a[i]%m);
		ret.pb(int(r));
	}
	return ret;
}
int main(){
	cin>>n>>m;
	rep(i,n){
		int a;cin>>a;used[a]=1;if(a==0) used[m]=1;
	}
	for(int i=1;i<=m;i++) if(m%i==0) D.pb(i);
	for(int i=1;i<=m;i++){
		if(used[i]) continue;
		int f = __gcd(i,m);
		f = POSL(D,f);
		num[f].pb(i);
	}
	memset(dp,-1,sizeof(dp));
	memset(nxt,-1,sizeof(nxt));
	rec(0);
	vector<int>zip;
	int cur = 0;
	while(1){
		rep(i,num[cur].size()) zip.pb(num[cur][i]);
		if(nxt[cur] == -1) break;
		cur = nxt[cur];
	}
	vector<int>ans = rev(zip);
	cout << ans.size() << endl;
	rep(i,ans.size()) cout << ans[i]%m << " ";
	cout << endl;
}