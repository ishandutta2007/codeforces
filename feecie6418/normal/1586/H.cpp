#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
char buf[5000005];
int p1=5000000;
char gc(){
	if(p1>=5000000)fread(buf,1,5000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int ch=gc(),x=0;
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))x=x*10+ch-'0',ch=gc();
	return x;
}
int n,Q,a[400005],b[400005],tot,c[6000005][2],mxmx[6000005],Size[400005],ans1[400005],ans2[400005],used[400005];
int root[400005],cnt,h[400005],mn[400005],mx[400005],X[400005],Y[400005];
int fa[400005],mxbc[400005],tb[400005],iscl[400005],cl[400005];
struct E{
	int to,next,w1,w2;
}e[400005];
struct E2{
	int x,y,val;
}edge[400005];
struct Query{
	int x,y,id;
};
vector<Query> q[200005];
void Add(int x,int y,int w1,int w2){
	e[++cnt]=(E){y,h[x],w1,w2},h[x]=cnt;
}
void Clear(){
	//cerr<<tot<<'\n';
	for(int i=1;i<=tot;i++)c[i][0]=c[i][1]=mxmx[i]=0;
	tot=0;
	for(int i=1;i<=cl[0];i++)root[cl[i]]=0,iscl[cl[i]]=0;
	cl[0]=0;
}
void Getsize(int x,int fa){
	Size[x]=1;
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(!used[y]&&y!=fa)Getsize(y,x),Size[x]+=Size[y];
	}
}
void Findcenter(int x,int fa,int all,int &mn,int &ct){
	int mx=all-Size[x];
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(!used[y]&&y!=fa)Findcenter(y,x,all,mn,ct),mx=max(mx,Size[y]);
	}
	if(mx<mn)mn=mx,ct=x;
}
void Ins(int &p,int l,int r,int x,int y){
	if(!p)p=++tot;
	mxmx[p]=max(mxmx[p],y);
	if(l==r)return ;
	int mid=(l+r)/2;
	if(x<=mid)Ins(c[p][0],l,mid,x,y);
	else Ins(c[p][1],mid+1,r,x,y);
}
int Que(int p,int l,int r,int x){
	if(!p)return -1;
	if(l>=x)return mxmx[p];
	int ret=-1,mid=(l+r)/2;
	ret=max(ret,Que(c[p][1],mid+1,r,x));
	if(x<=mid)ret=max(ret,Que(c[p][0],l,mid,x));
	return ret;
}
void dfs_ans(int x,int fa,int mnn,int mxx){
	mn[x]=mnn,mx[x]=mxx;
	//printf("x=%d mn=%d mx=%d\n",x,mn[x],mx[x]);
	for(Query i:q[x])
		if(mnn>=i.y){
			int ret=Que(root[ans1[i.id]],1,tb[0],i.y);
			if(ret>=0)ans2[i.id]=max(ans2[i.id],max(mxx,ret));//mn>=i.y
		}
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa&&!used[e[i].to])dfs_ans(e[i].to,x,min(mnn,e[i].w1),max(mxx,e[i].w2));
}
void Mark(int x){
	if(!iscl[x])iscl[x]=1,cl[++cl[0]]=x;
}
void dfs_ins(int x,int fa){
	Ins(root[a[x]],1,tb[0],mn[x],mx[x]),Mark(a[x]);
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa&&!used[e[i].to])dfs_ins(e[i].to,x);
}
void Dianfenzhi(int cur){
	int mnc=1e9,x=0;
	Getsize(cur,0),Findcenter(cur,0,Size[cur],mnc,x),used[x]=1;
	//cout<<x<<'\n';
	mx[x]=0,mn[x]=tb[0],Ins(root[a[x]],1,tb[0],mn[x],0),Mark(a[x]);
	//cout<<mn[x]<<' '<<mx[x]<<'\n';
	vector<int> u;
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(used[y])continue;
		//cout<<x<<"->"<<y<<'\n';
		u.push_back(y);
		dfs_ans(y,x,min(mn[x],e[i].w1),max(mx[x],e[i].w2));
		dfs_ins(y,x);
	}
	Clear();
	reverse(u.begin(),u.end());
	for(int y:u){
		dfs_ans(y,x,mn[y],mx[y]);
		dfs_ins(y,x);
	}
	for(Query i:q[x])ans2[i.id]=max(ans2[i.id],Que(root[ans1[i.id]],1,tb[0],i.y));//mn>=i.y
	Ins(root[a[x]],1,tb[0],mn[x],mx[x]),Mark(a[x]);
	Clear();//exit(0);
	//cout<<"CT:"<<x<<' '<<ans2[4]<<'\n';
	//exit(0);
	for(int i=h[x];i;i=e[i].next)if(!used[e[i].to])Dianfenzhi(e[i].to);
}
vector<Query> Qq;
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
void Merge(int x,int y){
	mxbc[gf(y)]=max(mxbc[gf(y)],mxbc[gf(x)]);
	fa[gf(x)]=gf(y);
	//cout<<"Merging:"<<x<<' '<<y<<'\n';
}
int main(){
	n=rd(),Q=rd();
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=a[i],fa[i]=i;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b,mxbc[i]=a[i];
	for(int i=1,x,y,w1,w2;i<n;i++)x=rd(),y=rd(),w1=rd(),w2=rd(),Add(x,y,w1,w2),Add(y,x,w1,w2),edge[i]={x,y,w1},tb[++tb[0]]=w1;
	sort(edge+1,edge+n,[](E2 x,E2 y){return x.val>y.val;});
	for(int i=1;i<=Q;i++)Y[i]=rd(),X[i]=rd();
	for(int i=1;i<=Q;i++)tb[++tb[0]]=Y[i];
	sort(tb+1,tb+tb[0]+1);
	for(int i=1;i<=Q;i++)Y[i]=lower_bound(tb+1,tb+tb[0]+1,Y[i])-tb;
	for(int i=1;i<=cnt;i++)e[i].w1=lower_bound(tb+1,tb+tb[0]+1,e[i].w1)-tb;
	for(int i=1;i<=n-1;i++)edge[i].val=lower_bound(tb+1,tb+tb[0]+1,edge[i].val)-tb;
	for(int i=1;i<=Q;i++)Qq.push_back({X[i],Y[i],i}),q[X[i]].push_back({X[i],Y[i],i});
	sort(Qq.begin(),Qq.end(),[](Query x,Query y){return x.y>y.y;});
	int j=0;
	for(Query i:Qq){
		while(j<n-1&&edge[j+1].val>=i.y)j++,Merge(edge[j].x,edge[j].y);
		ans1[i.id]=mxbc[gf(i.x)];
	}
	Dianfenzhi(1);
	for(int i=1;i<=Q;i++)printf("%d %d\n",b[ans1[i]],ans2[i]);
}