#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pr;
const int inf=1e9;
struct Edge{
	int to,nxt;
}e[1000005];
int n,m,h[500005],cnt=1,C=0,dfn[500005],bel[500005],st[500005],low[500005],sign,top;
int f[500005],sum[500005],cov[500005],p[500005][20],d[500005],q,cx[500005];
int ans,mxp1,mxp2,mx1,mx2,aa,bb,cc,dd;
pr t[2000005];
ll tag[2000005];
ull val[1000005],s[500005];
map<ull,int> mp1,mp2,mp3;
mt19937_64 rng(2333);
vector<int> per[500005];
void Add(int x,int y){
	e[++cnt]={y,h[x]},h[x]=cnt;
}
void Tarjan(int x,int fr){
	dfn[x]=low[x]=++sign,st[++top]=x;
	for(int i=1;i<=18;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].nxt){
		if((i^1)==fr)continue;
		int y=e[i].to;
		if(!dfn[y])p[y][0]=x,d[y]=d[x]+1,Tarjan(y,i),low[x]=min(low[x],low[y]),f[y]=i;
		else {
			low[x]=min(low[x],dfn[y]);
			if(x<y)val[i]=rng(),mp3[val[i]]=i,s[x]^=val[i],s[y]^=val[i];
		}
	}
	if(low[x]==dfn[x]){
		int tmp=0;
		C++;
		while(tmp!=x)tmp=st[top--],bel[tmp]=C;
	}
}
void upd(int w,int a,int b,int c,int d){
	if(w>ans)ans=w,aa=a,bb=b,cc=c,dd=d;
}
void dfs2(int x){
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(f[y]!=i)continue;
		dfs2(y),s[x]^=s[y],cov[x]+=cov[y];
	}
	if(x!=1&&s[x]==0){
		if(cov[x]>mx1)mx2=mx1,mxp2=mxp1,mx1=cov[x],mxp1=x;
		else if(cov[x]>mx2)mx2=cov[x],mxp2=x;
	}
	if(mp3.count(s[x])){
		upd(cov[x],x,p[x][0],e[mp3[s[x]]].to,e[mp3[s[x]]^1].to);
	}
	if(s[x]&&!mp2[s[x]])mp2[s[x]]=x;
}
void Tag(int p,ll z){
	tag[p]+=z,t[p].first+=z;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Build(int p,int l,int r){
	tag[p]=0;
	if(l==r)return t[p]=pr(-inf,l),void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=max(t[p*2],t[p*2+1]);
}
int Climb(int x,int y){
	for(int i=18;i>=0;i--)if(d[x]-(1<<i)>d[y])x=p[x][i];
	return x;
}
void Add(int p,int l,int r,int x,int y,ll z){
	if(y<1)return ;
	//if(p==1)cout<<"Adding:"<<x<<' '<<y<<' '<<z<<'\n';
	if(x<=l&&r<=y)return Tag(p,2*z);
	Pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)Add(p*2,l,mid,x,y,z);
	if(mid<y)Add(p*2+1,mid+1,r,x,y,z);
	t[p]=max(t[p*2],t[p*2+1]);
}
void Upd(int p,int l,int r,int x,int y){
	if(x<1)return ;
	if(l==r)return t[p]=pr(tag[p]+y,l),void();
	Pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)Upd(p*2,l,mid,x,y);
	else Upd(p*2+1,mid+1,r,x,y);
	t[p]=max(t[p*2],t[p*2+1]);
}
pr Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	int mid=(l+r)>>1;
	Pushdown(p);
	pr ret=pr(-inf,0);
	if(x<=mid)ret=max(ret,Query(p*2,l,mid,x,y));
	if(mid<y)ret=max(ret,Query(p*2+1,mid+1,r,x,y));
	return ret;
}
vector<int> hard_paths[500005];
int mindep[500005];
void dfs3(int x){
	//cout<<"inside "<<x<<'\n';
	st[d[x]]=x;
	Add(1,1,n,1,d[x]-1,cx[x]);
	for(int y:hard_paths[x])Add(1,1,n,1,d[y],-1);
	//for(int y:hard_paths[x])if(y>0)Add(1,1,n,1,d[y],1);
	if(s[x]){
		pr ret=Query(1,1,n,d[mp1[s[x]]],d[x]);
		//cout<<"query "<<x<<'\n';
		if(ret.first>=0)upd(ret.first-cov[x],x,p[x][0],st[ret.second],st[ret.second-1]);
		//if(ret.first-cov[x]==2)cout<<"RET@"<<x<<'\n';
	}
	for(int y:per[x])Add(1,1,n,1,d[y],-1);
	//for(int y:hard_paths[x])if(y<0)Add(1,1,n,1,d[-y],-1);
	Upd(1,1,n,d[x],cov[x]);
	if(s[x]&&mp2[s[x]]==x){
		Add(1,1,n,d[mp1[s[x]]],d[mp2[s[x]]],-inf);
	}
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(f[y]!=i)continue;
		dfs3(y);
	}
	Add(1,1,n,1,d[x]-1,-cx[x]);
	Upd(1,1,n,d[x],-inf);
	for(int y:per[x])Add(1,1,n,1,d[y],1);
	if(s[x]&&mp2[s[x]]==x){
		Add(1,1,n,d[mp1[s[x]]],d[mp2[s[x]]],inf);
	}
	//for(int y:hard_paths[x])if(y<0)Add(1,1,n,1,d[-y],1);
	//for(int y:hard_paths[x])if(y>0)Add(1,1,n,1,d[y],-1);
	for(int y:hard_paths[x])Add(1,1,n,1,d[y],1);
}
multiset<pr> paths;
void dfs4(int x){
	int son=0;
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(f[y]!=i)continue;
		if(mindep[y]<=d[x]){
			son=y;
			continue;
		}
		dfs4(y);
		while(1){
			auto it=paths.lower_bound(pr(d[x]+1,0));
			if(it==paths.end())break;
			paths.erase(it);
		}
	}
	//cout<<"son:"<<x<<' '<<son<<'\n';
	if(son){
		int de=d[mp1[s[son]]];
		while(1){
			auto it=paths.lower_bound(pr(de,0));
			if(it==paths.end())break;
			if((it->first)>d[x]){
				paths.erase(it);
				continue;
			}
			hard_paths[son].push_back(p[it->second][0]);
			paths.erase(it);
			//cout<<"hard path"<<son<<' '<<it->second<<'\n';
		}
		dfs4(son);
		while(1){
			auto it=paths.lower_bound(pr(d[x]+1,0));
			if(it==paths.end())break;
			paths.erase(it);
		}
	}
	for(int y:per[x])paths.insert(pr(d[y]+1,Climb(x,y)));
}
void getmindep(int x){
	if(s[x]&&!mp1[s[x]])mp1[s[x]]=x;
	if(s[x])mindep[x]=d[mp1[s[x]]];// 
	else mindep[x]=1e9;
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(f[y]!=i)continue;
		getmindep(y);
		mindep[x]=min(mindep[x],mindep[y]);
	}
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=18;i>=0;i--)if(d[x]-(1<<i)>=d[y])x=p[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(p[x][i]^p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
void Solve(){
	scanf("%d%d",&n,&m),ans=mx1=mx2=-1;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	Tarjan(1,0),scanf("%d",&q);
	for(int i=1,x,y,z;i<=q;i++){
		scanf("%d%d",&x,&y),cov[x]++,cov[y]++,cov[z=LCA(x,y)]-=2;
		if(x!=z)per[x].push_back(z),cx[Climb(x,z)]++;
		if(y!=z)per[y].push_back(z),cx[Climb(y,z)]++;
	}
	dfs2(1),getmindep(1),dfs4(1),Build(1,1,n),dfs3(1);
	//for(int i=1;i<=n;i++)printf("fa[%d]=%d s[%d]=%llu\n",i,p[i][0],i,s[i]);
	//cout<<"---------- ans ---------"<<ans<<'\n';
	if(mx1+max(mx2,0)>ans){
		cout<<mx1+max(mx2,0)<<'\n';
		cout<<mxp1<<' '<<p[mxp1][0]<<'\n';
		if(mx2>=0)cout<<mxp2<<' '<<p[mxp2][0]<<'\n';
		else {
			for(int i=1,fl=0;i<=n&&!fl;i++){
				for(int j=h[i];j&&!fl;j=e[j].nxt){
					int k=e[j].to;
					if(p[i][0]!=k&&p[k][0]!=i)cout<<i<<' '<<k<<'\n',fl=1;
				}
			}
		}
	}
	else if(ans!=-1){
		cout<<ans<<'\n';
		cout<<aa<<' '<<bb<<'\n';
		cout<<cc<<' '<<dd<<'\n';
	}
	else {
		puts("0");
		for(int i=1,fl=0;i<=n&&fl<2;i++){
			for(int j=h[i];j&&fl<2;j=e[j].nxt){
				int k=e[j].to;
				if(i<k)cout<<i<<' '<<k<<'\n',fl++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		h[i]=dfn[i]=bel[i]=st[i]=low[i]=cx[i]=f[i]=sum[i]=cov[i]=d[i]=s[i]=0;
		per[i].clear(),memset(p[i],0,sizeof(p[i])),hard_paths[i].clear(),mindep[i]=0;
	}
	paths.clear();
	for(int i=1;i<=cnt;i++)e[i]={0,0},val[i]=0;
	cnt=1,C=sign=top=0;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}