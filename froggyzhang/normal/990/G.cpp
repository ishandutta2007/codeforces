#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
ll ans[N];
int n,a[N],mx,root,maxp[N],vis[N];
int siz[N],head[N],cnt;
map<int,int> tot,num;
map<int,int>::iterator p,q;
struct Edge{
	int to,nxt;
}edge[N<<1];
inline void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
inline int _gcd(int a,int b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
void get_root(int u,int fa,int total){
	siz[u]=1;
	maxp[u]=0;
	for(register int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(siz[v],maxp[u]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!root||maxp[u]<maxp[root]){
		root=u;
	}
}
void get_ans(int u,int fa,int now){
	num[now]++;
	for(register int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v]||v==fa)continue;
		get_ans(v,u,_gcd(now,a[v]));
	}
}
void calc(int u){
	tot.clear();
	ans[a[u]]++;
	tot[a[u]]++;
	for(register int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		num.clear();
		get_ans(v,u,_gcd(a[u],a[v]));
		for(p=tot.begin();p!=tot.end();++p){
			int a1=p->first,a2=p->second;
			for(q=num.begin();q!=num.end();++q){
				ans[_gcd(a1,q->first)]+=1LL*a2*(q->second);
			}
		}
		for(q=num.begin();q!=num.end();++q){
			tot[q->first]+=(q->second);
		}
	}
}
void Solve(int u){
	vis[u]=1;
	calc(u);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		root=0;
		get_root(v,0,siz[v]);
		Solve(root);
	}
}
int main(){
	//freopen("d52.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	maxp[0]=n;
	get_root(1,0,n);
	Solve(root);
	for(int i=1;i<=mx;i++){
		if(ans[i]>0){
			printf("%d %lld\n",i,ans[i]);
		}
	}
	return 0;
}