#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,bel[600005],C,dfn[600005],low[600005],sign,st[600005],top,p[600005][20],d[600005],sign2,A[600005];
int rt[600005],dfn2[600005],q,cnte,a[600005],tot,ex[900005],ey[900005],tmp[900005],is[900005],T;
int val[900005],sum[900005],c[900005][2],rev[900005],tag[900005],st2[900005],top2,cl[900005],iscl[900005];
int fa[900005];
struct E{
	int to,id;
};
vector<E> g1[900005];
vector<int> g[900005],id[900005];//g
unordered_map<ll,int> mp;
void Tarjan(int x,int prt){
	dfn[x]=low[x]=++sign,st[++top]=x;
	for(E i:g1[x]){
		if(i.id==prt)continue;
		int y=i.to;
		if(!dfn[y])Tarjan(y,i.id),low[x]=min(low[x],low[y]);
		else low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		int tmp=0;
		C++;
		while(tmp!=x)tmp=st[top--],bel[tmp]=C;
	}
}
void dfs(int x,int fa,int fr){
	//cout<<x<<' '<<fa<<' '<<fr<<endl;
	rt[x]=fr,p[x][0]=fa,d[x]=d[fa]+1,dfn2[x]=++sign2;
	for(int i=1;i<=18;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int y:g[x])if(y^fa)dfs(y,x,fr);
}
int LCA(int x,int y){//fr[x]=fr[y]
	assert(rt[x]==rt[y]); 
	if(d[x]<d[y])swap(x,y);
	for(int i=18;i>=0;i--)if(d[p[x][i]]>=d[y])x=p[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(p[x][i]^p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
void Add(int x){
	if(!is[rt[x]])is[rt[x]]=1,tmp[++tmp[0]]=rt[x];
	id[rt[x]].push_back(x);
} 
void Cl(int x){
	c[x][0]=c[x][1]=fa[x]=rev[x]=tag[x]=sum[x]=val[x]=0;
}
void Tag(int x){
	tag[x]=1,sum[x]=val[x]=0;
}
void Rev(int x){
	rev[x]^=1,swap(c[x][0],c[x][1]);
}
void Pushdown(int x){
	if(tag[x])Tag(c[x][0]),Tag(c[x][1]),tag[x]=0;
	if(rev[x])Rev(c[x][0]),Rev(c[x][1]),rev[x]=0;
}
void Pushup(int x){
	sum[x]=sum[c[x][0]]+val[x]+sum[c[x][1]];
}
bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}
int findroot(int x){
	assert(isroot(x));
	while(c[x][0])x=c[x][0];
	return x;
}
void Rotate(int x){
	int y=fa[x],z=fa[y],l=(c[y][0]!=x),r=!l;
	if(!isroot(y)){
		if(c[z][0]==y)c[z][0]=x;
		else c[z][1]=x;
	}
	fa[x]=z,fa[y]=x,fa[c[x][r]]=y,c[y][l]=c[x][r],c[x][r]=y;
	Pushup(y),Pushup(x);
}
void Splay(int x){
	int t=x;
	st2[top2=1]=x;
	while(!isroot(t))t=fa[t],st2[++top2]=t;
	while(top2)Pushdown(st2[top2--]);
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if((c[y][0]==x)!=(c[z][0]==y))Rotate(x);
			else Rotate(y);
		}
		Rotate(x);
	}
}
void Access(int x){
	int y;
	Splay(x),c[x][1]=0,Pushup(x);
	for(y=x,x=fa[x];x;y=x,x=fa[x])Splay(x),c[x][1]=y,Pushup(x);
}
void Makeroot(int x){
	Access(x),Splay(x),Rev(x);
}
void Link(int x,int y){
	if(!iscl[x])cl[++cl[0]]=x,iscl[x]=1;
	if(!iscl[y])cl[++cl[0]]=y,iscl[y]=1;
	Makeroot(x),Access(y),Splay(y);
	if(findroot(y)!=x)fa[x]=y;
	else Tag(y);
}
int Find(int x,int y){
	Makeroot(x),Access(y),Splay(y);
	if(findroot(y)!=x)return -1;
	else return sum[y];
}
void AddV(int x,int y,int z){
	++T,val[T+n]=sum[T+n]=z,Link(x,T+n),Link(y,T+n);
}
void MakeTree(int rt){
	sort(id[rt].begin(),id[rt].end(),[](int x,int y){return dfn2[x]<dfn2[y];});
	id[rt].resize(unique(id[rt].begin(),id[rt].end())-id[rt].begin());
	if(id[rt].size()<=1)return ;
	st[top=1]=LCA(id[rt].front(),id[rt].back());
	for(int x:id[rt]){
		while(top>1&&LCA(x,st[top-1])!=st[top-1])AddV(st[top],st[top-1],d[st[top]]-d[st[top-1]]),top--;
		int tmp=LCA(st[top],x);
		if(tmp!=st[top]){
			AddV(st[top],tmp,d[st[top]]-d[tmp]);
			st[top]=tmp;
		}
		if(x!=st[top])st[++top]=x;
	}
	for(int i=2;i<=top;i++)AddV(st[i],st[i-1],d[st[i]]-d[st[i-1]]);
}
int R=0;
int rotate(int element)
{
   element=(element+R)%n;
   if (element==0) {
       element=n;
   }
   return element;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),g1[x].push_back({y,i}),g1[y].push_back({x,i});
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i,0);
	for(int i=1;i<=n;i++){
		for(E j:g1[i]){
			int x=bel[i],y=bel[j.to];
			if(x>y)swap(x,y);
			if(x==y||mp[300005ll*x+y])continue;
			mp[300005ll*x+y]=1,g[x].push_back(y),g[y].push_back(x);
		}
	}
	for(int i=1;i<=C;i++)if(!d[i])dfs(i,0,i);
	int Tt=0;
	while(q--){
		Tt++;
		int cntw;
		scanf("%d%d",&cntw,&cnte),T=0;
		for(int i=1;i<=cntw;i++)scanf("%d",&A[i]),Add(A[i]=bel[rotate(A[i])]);
		for(int i=1;i<=cnte;i++)scanf("%d%d",&ex[i],&ey[i]),Add(ex[i]=bel[rotate(ex[i])]),Add(ey[i]=bel[rotate(ey[i])]);
		for(int i=1;i<=tmp[0];i++)MakeTree(tmp[i]);
		for(int i=1;i<=cnte;i++)AddV(ex[i],ey[i],1);
		bool flag=1;
		for(int i=1;i<cntw;i++)if(Find(A[i],A[i+1])!=0)flag=0;
		puts(flag?"YES":"NO"),R+=Tt*flag,R%=n;
		while(cl[0])Cl(cl[cl[0]]),iscl[cl[cl[0]--]]=0;
		for(int i=1;i<=tmp[0];i++)id[tmp[i]].clear(),is[tmp[i]]=0;
		tmp[0]=0;
	}
}