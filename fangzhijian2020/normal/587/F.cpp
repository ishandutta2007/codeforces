#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,base,bl[100005],maxx,cnt,q[100005],l,r,h[100005],tot=1,top,Time,in[100005],out[100005];
long long sum1[100005],sum2[100005],vis[100005],s[100005],ans[100005];
struct edge{int to,next;}e[100005];
void addedge(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
struct trie{int ch[26],fail;}a[100005];
vector<int>v[100005];char c[100005];
struct query{
	int l,r,k,id;
	bool operator<(const query &a)const{
		return v[k].size()<v[a.k].size();
	}
}Q[100005];
struct Query{
	int x,id,opt,k;
	bool operator<(const Query &a)const{
		if(x==a.x)return k<a.k;
		return x<a.x;
	}
}p[200005];
void Insert(char *c,int id){
	int len=strlen(c+1),p=1;v[id].push_back(p);maxx+=len;
	for(int i=1;i<=len;++i){
		int x=int(c[i]-'a');
		if(!a[p].ch[x])a[p].ch[x]=++tot;
		p=a[p].ch[x];v[id].push_back(p); 
	}
}
void build(){
	int x,y;
	l=0;r=1;q[r]=1;a[1].fail=0;
	while(l<r){
		x=q[++l];
		for(int i=0;i<26;++i){
			int y=a[x].ch[i],t=a[x].fail;
			if(!y)continue;q[++r]=y;
			while(t&&!a[t].ch[i])t=a[t].fail;
			if(t)a[y].fail=a[t].ch[i];else a[y].fail=1;
			addedge(a[y].fail,y);
		}
	}
}
void dfs(int x){
	int i,y;in[x]=++Time;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs(y);
	}
	out[x]=Time;
}
void DFS(int x){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;DFS(y);vis[x]+=vis[y];
	}
}
void add(int l,int r){
	if(bl[l]==bl[r]){
		for(int i=l;i<=r;++i)++sum1[i];return;
	}
	for(int i=l;bl[i]==bl[l];++i)++sum1[i];
	for(int i=r;bl[i]==bl[r];--i)++sum1[i];
	for(int i=bl[l]+1;i<bl[r];++i)++sum2[i];
}
int ask(int x){return sum1[x]+sum2[bl[x]];}
bool cmp(const query a,const query b){return a.k<b.k;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){scanf("%s",c+1);Insert(c,i);}
	build();dfs(1);base=ceil(sqrt(maxx));
	for(int i=1;i<=tot;++i)bl[i]=(i-1)/base+1;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].k);Q[i].id=i;
		if(v[Q[i].k].size()<=base)++top;
	}
	sort(Q+1,Q+m+1);
	for(int i=1;i<=top;++i){
		p[(i<<1)-1]=(Query){Q[i].l-1,Q[i].id,-1,Q[i].k};
		p[(i<<1)]=(Query){Q[i].r,Q[i].id,1,Q[i].k};
	}
	sort(p+1,p+(top<<1)+1);int now=1;
	while(now<=(top<<1)&&p[now].x<=0){
		int tmp=v[p[now].k].size();
		for(int j=0;j<tmp;++j){
			ans[p[now].id]+=p[now].opt*ask(in[v[p[now].k][j]]);
		}
		++now;
	}
	for(int i=1;i<=n;++i){
		int tmp=v[i].size()-1;
		add(in[v[i][tmp]],out[v[i][tmp]]);
		while(now<=(top<<1)&&p[now].x<=i){
			int tmp=v[p[now].k].size();
			for(int j=0;j<tmp;++j){
				ans[p[now].id]+=p[now].opt*ask(in[v[p[now].k][j]]);
			}
			++now;
		}
	}
	for(int i=top+1;i<=m;++i)Q[i-top]=Q[i];top=m-top;
	sort(Q+1,Q+top+1,cmp);
	for(int i=1;i<=top;++i){
		if(Q[i-1].k!=Q[i].k){
			memset(vis,0,sizeof(vis));
			int tmp=v[Q[i].k].size();
			for(int j=0;j<tmp;++j)++vis[v[Q[i].k][j]];	
			DFS(1);
			for(int j=1;j<=n;++j){
				int t=v[j].size()-1;
				s[j]=s[j-1]+vis[v[j][t]];
			}
		}
		ans[Q[i].id]=s[Q[i].r]-s[Q[i].l-1];
	}
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}