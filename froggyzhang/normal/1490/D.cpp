#include<bits/stdc++.h>
using namespace std;
#define N 3030
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
int T,n,a[N],dep[N];
struct node{
	int ch[2];	
}t[N];
#define ls t[u].ch[0]
#define rs t[u].ch[1]
void dfs(int u){
	if(ls)dep[ls]=dep[u]+1,dfs(ls);
	if(rs)dep[rs]=dep[u]+1,dfs(rs);
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		t[i].ch[0]=t[i].ch[1]=0;
	}
	static int st[N],top;
	top=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]>a[st[top]])t[i].ch[0]=st[top--];
		if(top)t[st[top]].ch[1]=i;
		st[++top]=i;	
	}
	dep[st[1]]=0;
	dfs(st[1]);
	for(int i=1;i<=n;++i){
		printf("%d ",dep[i]);
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