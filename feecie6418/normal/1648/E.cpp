#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,ff[400005],p[400005][20],v[400005],N,d[400005];
int dfn[400005],sign,id[400005],c[400005],isin[400005];
struct Edge{
	int x,y,z;
}e[400005];
struct E{
	int to,val;
};
vector<int> g[400005];
vector<E> gg[400005];
int gf(int x){
	return ff[x]==x?x:ff[x]=gf(ff[x]);
}
int LCA(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=18;i>=0;i--)if(d[x]-(1<<i)>=d[y])x=p[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(p[x][i]^p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
void dfs(int x,int f){
	p[x][0]=f,d[x]=d[f]+1;
	if(x<=n)dfn[x]=++sign,id[sign]=x;
	for(int i=1;i<=18;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(int y:g[x])dfs(y,x);
}
vector<int> in[400005],no[400005];
void U(int x,int y){
	while(x<=n)c[x]+=y,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void Find(int &mnv,int &fr,int &to,int d1){
	//=Q(d1)
	int s=Q(d1),cur=0;
	for(int i=18;i>=0;i--)if(cur+(1<<i)<=n&&c[cur+(1<<i)]<=s)cur+=(1<<i),s-=c[cur];
	if(cur<n){
		cur++;
		int x=id[d1],y=id[cur],val=v[LCA(x,y)];
		if(val<mnv)mnv=val,fr=x,to=y;
	}
	s=Q(d1),cur=0;
	//<Q(d1) 
	if(!s)return ;
	for(int i=18;i>=0;i--)if(cur+(1<<i)<=n&&c[cur+(1<<i)]<s)cur+=(1<<i),s-=c[cur];
	//cerr<<d1<<' '<<cur<<'\n'
	if(cur<n){
		cur++;
	//assert(cur!=d1);
		int x=id[d1],y=id[cur],val=v[LCA(x,y)];
		if(val<mnv)mnv=val,fr=x,to=y;
	}
}
struct Be{
	int x,y,z;
}bb[400005];
bool Do(){
	int bs=0;
	for(int i=1;i<=n;i++)in[gf(i)].push_back(i);
	for(int i=1;i<=n;i++)U(i,1);
	for(int i=1;i<=n;i++){
		if(gf(i)!=i)continue;
		for(int j:in[i])U(dfn[j],-1),isin[j]=1;
		//cout<<"Trying:"<<i<<'\n';
		//for(int j:in[i])cout<<j<<",";
		//puts("");
		int mnv=2e9,fr=0,to=0;
		for(int j:in[i]){
			for(int k:no[j]){
				if(isin[k])continue;
				U(dfn[k],-1);
			}
			Find(mnv,fr,to,dfn[j]);
			for(int k:no[j]){
				if(isin[k])continue;
				U(dfn[k],1);
			}
		}
		//cout<<"I:"<<i<<' '<<fr<<' '<<to<<' '<<mnv<<'\n';
		if(fr||to){
			bb[++bs]={fr,to,mnv};
		}
		for(int j:in[i])U(dfn[j],1),isin[j]=0;
	}
	for(int i=1;i<=n;i++)in[i].clear(),c[i]=0;
	if(!bs)return 0;
	for(int i=1;i<=bs;i++){
		int x=bb[i].x,y=bb[i].y,z=bb[i].z;
		if(gf(x)==gf(y))continue;
		gg[x].push_back({y,z}),gg[y].push_back({x,z});
		ff[gf(x)]=gf(y);
		//cout<<"Adding:"<<x<<' '<<y<<' '<<z<<'\n';
	}
	return 1;
}
int pp[400005][20],mm[400005][20],X[400005],Y[400005],dd[400005];
void dfs2(int x,int f,int lst){
	pp[x][0]=f,mm[x][0]=lst,dd[x]=dd[f]+1;
	for(int i=1;i<=18;i++){
		pp[x][i]=pp[pp[x][i-1]][i-1];
		mm[x][i]=max(mm[x][i-1],mm[pp[x][i-1]][i-1]);
	}
	for(E i:gg[x]){
		int y=i.to;
		if(y==f)continue;
		dfs2(y,x,i.val);
	}
}
int Getmx(int x,int y){
	if(dd[x]<dd[y])swap(x,y);
	int mx=0;
	for(int i=18;i>=0;i--)if(dd[x]-(1<<i)>=dd[y])mx=max(mx,mm[x][i]),x=pp[x][i];
	if(x==y)return mx;
	for(int i=18;i>=0;i--)if(pp[x][i]^pp[y][i])mx=max(mx,max(mm[x][i],mm[y][i])),x=pp[x][i],y=pp[y][i];
	return max(mx,max(mm[x][0],mm[y][0]));
}
void Solve(){
	scanf("%d%d",&n,&m),N=n;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		no[e[i].x].push_back(e[i].y);
		no[e[i].y].push_back(e[i].x);
		X[i]=e[i].x,Y[i]=e[i].y;
	}
	sort(e+1,e+m+1,[](Edge x,Edge y){return x.z<y.z;});
	for(int i=1;i<=n;i++)ff[i]=i;
	for(int i=1;i<=m;i++){
		int x=gf(e[i].x),y=gf(e[i].y);
		if(x==y)continue;
		++N;
		g[N].push_back(x),g[N].push_back(y),v[N]=e[i].z;
		ff[N]=N,ff[x]=ff[y]=N;
	}
	//Boruvka
	for(int i=1;i<=n;i++)ff[i]=i;
	dfs(N,0);
	while(Do());
	dfs2(1,0,0);
	for(int i=1;i<=m;i++)printf("%d ",Getmx(X[i],Y[i]));
	puts("");
	for(int i=1;i<=N;i++){
		ff[i]=v[i]=dfn[i]=id[i]=c[i]=isin[i]=d[i]=dd[i]=0;
		memset(p[i],0,sizeof(p[i]));
		memset(pp[i],0,sizeof(pp[i]));
		memset(mm[i],0,sizeof(mm[i]));
		g[i].clear(),gg[i].clear(),no[i].clear();
	}
	sign=N=0;
	for(int i=1;i<=m;i++)X[i]=Y[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}