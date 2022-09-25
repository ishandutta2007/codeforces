#include<bits/stdc++.h>
using namespace std;
#define N 1505
typedef long long ll;
int n,m,S,k,a[N],s[N];
struct Seg{
	int l,r;
	friend bool operator < (const Seg &a,const Seg &b){
		return a.r==b.r?a.l>b.l:a.r<b.r;
	}	
}g[N];
bool check(int x){
	static int dp[N][N];
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+(a[i]<=x);	
	}
	int mx=0;
	for(int i=1;i<=m;++i){
		mx=max(mx,dp[1][i]=s[g[i].r]-s[g[i].l-1]);	
	}
	for(int i=2;i<=S;++i){
		static int q[N],l,r,pre[N];
		q[l=r=1]=0;
		for(int j=1;j<=m;++j){
			pre[j]=max(pre[j-1],dp[i-1][j]);	
		}
		for(int j=1,k=0;j<=m;++j){
			while(k<j&&g[k+1].r<g[j].l)++k;
			while(l<=r&&q[l]<=k)++l;
			mx=max(mx,dp[i][j]=max(pre[k]+s[g[j].r]-s[g[j].l-1],l<=r?dp[i-1][q[l]]+s[g[j].r]-s[g[q[l]].r]:0));
			while(l<=r&&dp[i-1][j]-s[g[j].r]>=dp[i-1][q[r]]-s[g[q[r]].r])--r;
			q[++r]=j;
		}
	}
	return mx>=k;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>S>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(int i=1;i<=m;++i){
		cin>>g[i].l>>g[i].r;
	}
	int _m=0;
	sort(g+1,g+m+1);
	for(int i=1;i<=m;++i){
		while(_m&&g[_m].l>=g[i].l)--_m;
		g[++_m]=g[i];
	}
	m=_m;
	int l=1,r=1e9+1,ans=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}	
	}
	cout<<ans<<'\n';
	return 0;
}