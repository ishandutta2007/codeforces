#include <bits/stdc++.h>
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
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<int>d[300005],dv[300005];
bool bad[300005];
int n,a[300005];
ll mod[3]={1000000007,1000000009,998244353};
int cnt[300005];
ll modpow(ll x,ll n,int c){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod[c];
		x=x*x%mod[c];
		n>>=1;
	}
	return res;
}
ll F[300005][3],R[300005][3];
void make(){
	rep(j,3) F[0][j] = 1;
	rep(c,3) for(int i=1;i<300005;i++) F[i][c] = F[i-1][c]*i%mod[c];
	rep(c,3) for(int i=0;i<300005;i++) R[i][c] = modpow(F[i][c],mod[c]-2,c);
}
ll C(int a,int b,int c){
	return F[a][c]*R[b][c]%mod[c]*R[a-b][c]%mod[c];
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=300000;i++){
		if(d[i].size()) continue;
		for(int j=1;i*j<=300000;j++){
			d[i*j].pb(i);
		}
	}
	for(int i=2;i<=300000;i++){
		for(int j=1;i*j<=300000;j++){
			dv[i*j].pb(i);
		}
	}
	rep(i,n){
		rep(j,dv[a[i]].size()){
			cnt[dv[a[i]][j]]++;
		}
	}
	for(int i=2;i<=300000;i++){
		for(int j=0;j<d[i].size();j++){
			int x = i/d[i][j];
			if(x%d[i][j] == 0){
				bad[i] = 1;
			}
		}
	}
	make();
	//(lb,ub]
	int lb = 0,ub = n+1;
	while(ub-lb>1){
		int mid = (lb+ub)/2;
		ll x[3];
		rep(c,3) x[c] = C(n,mid,c);
		ll y[3] = {};
		for(int i=2;i<=300000;i++){
			if(bad[i]) continue;
			ll py = d[i].size()%2;
			if(py == 0) py = -1;
			int a = cnt[i];
			if(a < mid) continue;
			rep(c,3){
				y[c] += py*C(a,mid,c);
			}
		}
		bool ok = 0;
		rep(c,3){
			y[c] %= mod[c];
			y[c] = (y[c]+mod[c])%mod[c];
			if(x[c] != y[c]) ok = 1;
		}
		if(!ok) lb = mid;
		else ub = mid;
	}
	if(ub == n+1) ub = -1;
	cout << ub << endl;
}