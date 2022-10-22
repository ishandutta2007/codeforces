#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
#define maxn 100010
int head[maxn],v[maxn*2],nxt[maxn*2],tot=0;
void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
struct Seq{
	int a[15],len;
	Seq(){memset(a,127,sizeof(a));len=0;}
	friend Seq operator +(Seq &num1,Seq &num2){
		Seq ans;
		int l1=1,l2=1;
		while((l1<=num1.len||l2<=num2.len)&&ans.len<10){
			if(num1.a[l1]<num2.a[l2])ans.a[++ans.len]=num1.a[l1],++l1;
			else ans.a[++ans.len]=num2.a[l2],++l2;
		}
		return ans;
	}
}minv[maxn][17],Init[maxn];
int fa[maxn][17];
int depth[maxn];
void dfs(int u,int f){
	fa[u][0]=f;depth[u]=depth[f]+1;
	for(register int i=1;i<17;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
	minv[u][0]=minv[u][0]+Init[u];
	for(register int i=1;i<17;++i)minv[u][i]=minv[u][i-1]+minv[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i])
	if(v[i]!=f)dfs(v[i],u);
}
Seq go_up(int &k,int d){
	Seq ans;
	for(register int i=16;i>=0;--i)
	if(d&(1<<i)){ans=ans+minv[k][i];k=fa[k][i];}
	return ans;
}
Seq query(int s,int e){
	Seq ans;
	if(depth[s]>depth[e]){
		Seq now=go_up(s,depth[s]-depth[e]);
	    ans=ans+now;
    }
	if(depth[s]<depth[e]){
		Seq now=go_up(e,depth[e]-depth[s]);
	    ans=ans+now;
	}
	if(s==e)return ans+Init[s];
	for(register int i=16;i>=0;--i)
	if(fa[s][i]!=fa[e][i]){
		ans=ans+minv[s][i];
		ans=ans+minv[e][i];
		s=fa[s][i];
		e=fa[e][i];
	}
	ans=ans+minv[s][0];
	ans=ans+minv[e][0];
	ans=ans+Init[fa[s][0]];
	return ans;
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
    rd(n);rd(m);rd(q);
	int s,e;
	for(register int i=1;i<n;++i){
		rd(s);rd(e);
		add_edge(s,e);
	}
	for(register int i=1;i<=m;++i){
		rd(s);
		if(Init[s].len<10)Init[s].a[++Init[s].len]=i;
	}
	dfs(1,0);
	int u,v,a;
	for(register int i=1;i<=q;++i){
		rd(u);rd(v);rd(a);
		Seq ans=query(u,v);
		if(!ans.len)puts("0");
		else{
			printf("%d ",min(a,ans.len));
			for(int i=1;i<=min(a,ans.len);++i)printf("%d ",ans.a[i]);
			puts("");
		}	
	}
	return 0;
}