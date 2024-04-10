#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
int T,n,m,cnt[N],a[N],p[N];
bool check(int x){
	int cir=0;
	static int vis[N];
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		++cir;
		for(int u=i;!vis[u];u=p[(u-x+n-1)%n+1])vis[u]=1;
	}
	return cir>=n-m;
}
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[a[i]]=i;
		++cnt[(i-a[i]+n)%n];
	}
	vector<int> ans;
	for(int i=0;i<n;++i){
		if(cnt[i]>=n/3){
			if(check(i))ans.push_back(i);
		}	
	}
	printf("%d",(int)ans.size());
	for(auto x:ans)printf(" %d",x);
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}