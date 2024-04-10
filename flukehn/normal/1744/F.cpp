#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int p[N],a[N];
int n;
bool vis[N];
int now;
ll C(int n){ return 1LL*n*(n-1)/2;}
void solve(){
	cin>>n;
	For(i,0,n) cin>>a[i];
	For(i,0,n) p[a[i]]=i;
	For(i,0,n+3) vis[i]=0;
	ll ans=0;
	int l=p[0],r=p[0];
	now=0;
	vis[0]=1;
	for(int i=1;i<n;++i) {
		int v=p[i];
		while(vis[now]) now++;
		//assert(now>=i);
		if(now>i) {
			continue;
		}
		//assert(l>v||r<v);
		int s,t;
		if(l>v) s=l-v-1, t=n-r-1;
		else s=l, t=v-r-1;
		int w=i- (r-l+1-i);
		if(w>=0){
			ans+=C(w+2);
			if(w>=s) ans-=C(w-s+1);
			if(w>=t) ans-=C(w-t+1);
			if(w>=s+t) ans+=C(w-s-t);
		}
		dbg(i,ans);
		while(l>v) vis[a[--l]]=1;
		while(r<v) vis[a[++r]]=1;
	}
	ans+=1;
	cout<<ans<<"\n";
}

int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
}