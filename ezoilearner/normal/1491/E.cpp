#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
int n;
#define Maxn 200010
int to[Maxn];
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int F[100];
void init(){
	F[1]=1;F[2]=2;
	to[1]=1;to[2]=2;
	for(int i=3;i<=n;++i){
		F[i]=F[i-2]+F[i-1];
		if(F[i]>n)break;
		to[F[i]]=i;
	}
}

int vis[Maxn],siz[Maxn],visT=0;
pii rt;int sum;
void dfs(int u,int f){
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
		if(vis[v[i]]==visT&&v[i]!=f){
			dfs(v[i],u);
			siz[u]+=siz[v[i]];
		}
	if(to[siz[u]]&&to[sum-siz[u]])rt=pii(u,f);
}

int a[Maxn];int tag[Maxn],tagT=0;
void add(int u,int f,int &k){
	a[k]=u;++k;tag[u]=tagT;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f&&vis[v[i]]==visT)add(v[i],u,k);
}
void gao(int u,int f,int &k){
	if(tag[u]==tagT)return;
	a[k]=u;++k;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f&&vis[v[i]]==visT)gao(v[i],u,k);
}

bool solve(int l,int r){
	if(l==r)return true;
	visT++;
	rep(i,l,r)vis[a[i]]=visT;
	sum=r-l+1;
	rt=pii(0,0);dfs(a[l],0);int hh=a[l];
	if(!rt.FR)return false;
	int t=l;
	tagT++;add(rt.FR,rt.SE,t);
	int pre=t;
	gao(hh,0,t);
	return solve(l,pre-1)&&solve(pre,r);
}

int main(){
	rd(n);init();
	if(!to[n]){
		puts("NO");
		return 0;
	}
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,e);
	}
	rep(i,1,n)a[i]=i;
	if(solve(1,n))puts("YES");
	else puts("NO");
	return 0;
}