#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

int n;
#define Maxn 100010
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}
int rev(int x){
	if(x&1)return x+1;
	return x-1;
}

int ans[Maxn<<1];
int seq[Maxn],L;
void pre_dfs(int u,int f){
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			int t=v[i];
			pre_dfs(v[i],u);
			L=0;
			for(int j=head[t];j;j=nxt[j])
				if(v[j]!=u)seq[++L]=ans[j];
			ans[i]=L;
			sort(seq+1,seq+L+1);reverse(seq+1,seq+L+1);
			rep(j,1,L)ans[i]=max(ans[i],j-1+seq[j]);
		}
}

bool cmp(int a,int b){return ans[a]<ans[b];}
int suf[Maxn];
void gao(int u){
	L=0;
	for(int i=head[u];i;i=nxt[i])seq[++L]=i;
	sort(seq+1,seq+L+1,cmp);
	reverse(seq+1,seq+L+1);
	suf[L+1]=0;
	per(i,L,1)suf[i]=max(suf[i+1],i-1+ans[seq[i]]);
	int mx=0;
	rep(i,1,L){
		int t=rev(seq[i]);
		ans[t]=L-1;
		ans[t]=max(ans[t],mx);
		ans[t]=max(ans[t],suf[i+1]-1);
		mx=max(mx,i-1+ans[seq[i]]);
	}
}

void dfs(int u,int f){
	gao(u);
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f)dfs(v[i],u);
}

int calc(int u){
	L=0;
	for(int i=head[u];i;i=nxt[i])seq[++L]=ans[i];
	sort(seq+1,seq+L+1);reverse(seq+1,seq+L+1);
	int res=L;
	if(!L)return res;
	res=max(res,L-1+seq[1]);
	rep(i,2,L)res=max(res,seq[i]+seq[1]+i-2);
	return res;
}

int rt;

int vis[Maxn];

int ask(int x){
	if(vis[x])return vis[x];
	printf("? %d\n",x);fflush(stdout);
	scanf("%d",vis+x);return vis[x];
}
void report(int x,int y){
	printf("! %d %d\n",x,y);fflush(stdout);
}

vector<int> vec[Maxn];

void Build(int u,int f){
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			Build(v[i],u);
			vec[u].push_back(i);
		}
	sort(vec[u].begin(),vec[u].end(),cmp);
	reverse(vec[u].begin(),vec[u].end());
}


int in[Maxn],out[Maxn],dfk=0;
void build(int u){
	in[u]=dfk+1;
	for(int i=0;i<vec[u].size();++i)build(v[vec[u][i]]);
	if(vec[u].size()==0){
		seq[++dfk]=u;
	}
	out[u]=dfk;
}

int A,B;
void Find(int u){
	if(vec[u].size()==0){
		if(A==rt)A=u;
		else B=u;
		return;
	}
	for(int i=0;i<vec[u].size();++i){
		int t=v[vec[u][i]];
		if(ask(seq[in[t]])!=u){
			Find(t);
			return;
		}
	}
	if(A==rt)A=u;
	else B=u;
}

int main(){
	scanf("%d",&n);
	int s,e;
	rep(i,1,n-1){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}	
	pre_dfs(1,0);
	dfs(1,0);
	int Ans=0;
	rep(u,1,n)Ans=max(Ans,calc(u));
	printf("%d\n",Ans);
	fflush(stdout);
	scanf("%d",&rt);A=rt;B=rt;
	if(n==1){
		report(rt,rt);
		return 0;
	}
	Build(rt,0);
	build(rt);
	int at=0;
	for(int i=0;i<vec[rt].size();++i){
		int u=v[vec[rt][i]];
		if(ask(seq[in[u]])!=rt)Find(u),at++;
		if(at==2)break;
	}
	report(A,B);
	return 0;
}