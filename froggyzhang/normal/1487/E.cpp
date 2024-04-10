#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int inf=0x3f3f3f3f;
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
int n[5];
int a[5][N];
void Solve(int n1,int n2,int *a,int *b){
	static vector<int> G[N];
	static int p[N];
	for(int i=1;i<=n2;++i){
		G[i].clear();
	}
	int m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		G[y].push_back(x);
	}
	for(int i=1;i<=n1;++i)p[i]=i;
	sort(p+1,p+n1+1,[&](int i,int j){return a[i]<a[j];});
	for(int i=1;i<=n2;++i){
		static int vis[N];
		for(auto x:G[i])vis[x]=1;
		int j=1;
		for(;j<=n1;++j){
			if(!vis[p[j]]){b[i]+=a[p[j]];break;}
		}
		if(j>n1||b[i]>inf)b[i]=inf;		
		for(auto x:G[i])vis[x]=0;
	}
}
int main(){
	for(int i=1;i<=4;++i)n[i]=read();
	for(int i=1;i<=4;++i){
		for(int j=1;j<=n[i];++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<4;++i){
		Solve(n[i],n[i+1],a[i],a[i+1]);
	}
	int ans=inf;
	for(int i=1;i<=n[4];++i){
		ans=min(ans,a[4][i]);
	}
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}