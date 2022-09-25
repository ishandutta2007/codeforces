#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,Q,a[N],b[N],c[N],lg[N];
ll s[N],f[N][19],g[N][19];
inline ll Query_f(int l,int r){
	int k=lg[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
inline ll Query_g(int l,int r){
	int k=lg[r-l+1];
	return min(g[l][k],g[r-(1<<k)+1][k]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)c[i]=b[i]-a[i];
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+c[i];
	}
	for(int i=1;i<=n;++i){
		f[i][0]=g[i][0]=s[i];
	}
	for(int j=1;j<=18;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(int j=1;j<=18;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		ll ans=Query_f(l,r)-s[l-1];
		if(s[l-1]!=s[r]||Query_g(l,r)<s[l-1])ans=-1;
//		int now=0,ans=0;
//		for(int i=l;i<=r;++i){
//			now+=c[i];
//			if(now<0){
//				ans=-1;break;
//			}
//			ans=max(ans,now);
//		}
		printf("%lld\n",ans);
	}
	return 0;
}