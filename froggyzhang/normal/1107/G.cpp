#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,A;
ll ans,s[N],c[N],d[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>A;
	for(int i=1;i<=n;++i){
		cin>>d[i]>>c[i];	
	}
	for(int i=1;i<n;++i){
		d[i]=d[i+1]-d[i];
	}
	for(int i=1;i<=n;++i){
		c[i]=A-c[i];
		ans=max(ans,c[i]);
		s[i]=s[i-1]+c[i];
	}
	static int st[N],top;
	static ll g[N],pre[N];
	pre[0]=1e18;
	for(int i=1;i<n;++i){
		ll mn=s[i-1];
		while(top&&d[i]>=d[st[top]]){
			mn=min(mn,g[top]-d[st[top]]*d[st[top]]);
			--top;
		}
		st[++top]=i;
		g[top]=mn+d[i]*d[i];
		pre[top]=min(pre[top-1],g[top]);
		ans=max(ans,s[i+1]-pre[top]);
	}
	cout<<ans<<'\n';
	return 0;
}