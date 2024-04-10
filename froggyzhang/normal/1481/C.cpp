#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,a[N],b[N],cnt[N],c[N],vis[N],ans[N];
vector<int> p[N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)cnt[i]=vis[i]=0,p[i].clear();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
		vis[b[i]]=1;
		if(a[i]^b[i])++cnt[b[i]],p[b[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		c[i]=read();
	}
	if(!vis[c[m]])return (void)printf("NO\n");
	int fir=0;
	if(cnt[c[m]]){
		fir=p[c[m]][0];
	}
	else{
		for(int i=1;i<=n;++i){
			if(b[i]==c[m]){fir=i;break;}
		}
	}
	for(int i=1;i<=m;++i){
		if(cnt[c[i]]>0){
			ans[i]=p[c[i]].back();
			p[c[i]].pop_back();
			--cnt[c[i]];
		}
		else ans[i]=fir;
	}
	ans[m]=fir;
	for(int i=1;i<=n;++i){
		if(cnt[i]>0)return (void)printf("NO\n");
	}
	printf("YES\n");
	for(int i=1;i<=m;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}