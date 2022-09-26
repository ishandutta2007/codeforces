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
int c[N],n,m,l[N],r[N],n1,n2;
int L,R;
vector<int> G[N];
void dfs(int u){
	for(auto v:G[u]){
		if(~c[v]){
			if(c[u]==c[v]){printf("IMPOSSIBLE\n");exit(0);}
		}
		else{
			c[v]=c[u]^1;
			dfs(v);
		}
	}
}
int main(){
	L=read(),R=read();
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
	}
	n1=*min_element(r+1,r+n+1);
	n2=*max_element(l+1,l+n+1);
	if(n1+n2<L)n2+=L-n1-n2;
	else if(n1+n2>R)n1-=n1+n2-R;
	if(n1<0||n2<0)return !printf("IMPOSSIBLE\n");
	memset(c,-1,sizeof(c));
	for(int i=1;i<=n;++i){
		if(n1>=l[i]&&n1<=r[i]&&n2>=l[i]&&n2<=r[i])continue;
		if(n1>=l[i]&&n1<=r[i]){
			c[i]=0;
		}
		else if(n2>=l[i]&&n2<=r[i]){
			c[i]=1;
		}
		else return !printf("IMPOSSIBLE\n");
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		if(~c[i])dfs(i);
	}
	for(int i=1;i<=n;++i){
		if(!~c[i])c[i]=0,dfs(i);
	}
	printf("POSSIBLE\n");
	printf("%d %d\n",n1,n2);
	for(int i=1;i<=n;++i){
		putchar('1'+c[i]);
	}
	return 0;
}