#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=1e9+7;
const ll INF=1e18;
const int N=2e5+5,M=5e6+5;
const int ASDF=1<<24;
int n,s,t,a[N],d[N];
queue<int> Q;
struct segmentTree{
	pii T[2*N];
	void init(int nd,int l,int r){
		if(l==r){
			T[nd]=pii(min(n,l+a[l]),max(1,l-a[l]));
			return;
		}
		int m=(l+r)>>1;
		init(nd+1,l,m); init(nd+2*(m-l+1),m+1,r);
		T[nd]=pii(max(T[nd+1].fi,T[nd+2*(m-l+1)].fi),min(T[nd+1].se,T[nd+2*(m-l+1)].se));
	}
	void qry(int md,int nd,int l,int r,int s,int e,int v){
		if(r<s||e<l) return;
		if(s<=l&&r<=e&&md==0&&T[nd].fi<v) return;
		if(s<=l&&r<=e&&md==1&&T[nd].se>v) return;
		if(l==r){
			if(!d[l]){
				d[l]=d[v]+1;
				Q.emplace(l);
				T[nd].fi=-1e9;
				T[nd].se=1e9;
			}
			return;
		}
		int m=(l+r)>>1;
		qry(md,nd+1,l,m,s,e,v); qry(md,nd+2*(m-l+1),m+1,r,s,e,v);
		T[nd]=pii(max(T[nd+1].fi,T[nd+2*(m-l+1)].fi),min(T[nd+1].se,T[nd+2*(m-l+1)].se));
	}
}T;
void solve(){
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	T.init(1,1,n);
	for(int i=1;i<=n;i++) d[i]=0;
	d[s]=1;
	Q.emplace(s);
	while(Q.size()){
		int i=Q.front(); Q.pop();
		T.qry(0,1,1,n,max(1,i-a[i]),i,i);
		T.qry(1,1,1,n,i,min(n,i+a[i]),i);
	}
	cout<<d[t]-1<<"\n";
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}