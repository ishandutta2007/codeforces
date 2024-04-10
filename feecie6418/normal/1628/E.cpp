#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct Thing{
	int x,y,z;
}e[300005];
int n,q,d[600005],c[600005][2],dfn[600005],id[600005],tot,fa[600005],sign;
int f[600005][20],v[600005],lg2[600005],anyo[1200005],lca[1200005],cur[1200005];
int tag[1200005],L[1200005];
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
void dfs(int x,int dep){
	if(x<=n){
		dfn[x]=++sign,id[sign]=x,d[x]=dep;
		return ;
	}
	dfs(c[x][0],dep+1);
	dfn[x]=++sign,id[sign]=x,d[x]=dep;
	dfs(c[x][1],dep+1);
}
int LCA(int x,int y){
	if(!x||!y)return x+y;
	int p=dfn[x],q=dfn[y];
	if(p>q)swap(p,q);
	int k=lg2[q-p+1];
	if(d[f[p][k]]<d[f[q-(1<<k)+1][k]])return f[p][k];
	return f[q-(1<<k)+1][k];
}
void Build(int p,int l,int r){
	tag[p]=-1,anyo[p]=cur[p]=0,L[p]=l;
	if(l==r)return lca[p]=l,void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	lca[p]=LCA(lca[p*2],lca[p*2+1]);
}
void Tag(int p,int x){
	tag[p]=x;
	if(x==0)cur[p]=anyo[p]=0;
	else cur[p]=lca[p],anyo[p]=L[p];
}
void Pushdown(int p){
	if(~tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=-1;
}
void Make(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y,z);
	if(mid<y)Make(p*2+1,mid+1,r,x,y,z);
	cur[p]=LCA(cur[p*2],cur[p*2+1]);
	if(anyo[p*2])anyo[p]=anyo[p*2];
	else anyo[p]=anyo[p*2+1];
}
int p1=1000000;
char buf[1000005];
int gc(){
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
int main(){
	n=rd(),q=rd(),tot=n,lg2[0]=-1;
	for(int i=1,x,y,z;i<n;i++)x=rd(),y=rd(),z=rd(),e[i]={x,y,z};
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+n,[](Thing x,Thing y){return x.z<y.z;});
	for(int i=1;i<n;i++){
		int x=gf(e[i].x),y=gf(e[i].y),z=e[i].z;
		++tot,v[tot]=z;
		c[tot][0]=x,c[tot][1]=y;
		fa[x]=fa[y]=fa[tot]=tot;
	}
	dfs(tot,1);
	for(int i=1;i<=sign;i++)f[i][0]=id[i],lg2[i]=lg2[i>>1]+1;
	for(int j=1;j<=19;j++){
		for(int i=1;i+(1<<j)-1<=sign;i++){
			if(d[f[i][j-1]]<d[f[i+(1<<j-1)][j-1]])f[i][j]=f[i][j-1];
			else f[i][j]=f[i+(1<<j-1)][j-1];
		}
	}
	Build(1,1,n);
	for(int i=1,op,l,r;i<=q;i++){
		op=rd();
		if(op==1)l=rd(),r=rd(),Make(1,1,n,l,r,1);
		if(op==2)l=rd(),r=rd(),Make(1,1,n,l,r,0);
		if(op==3){
			l=rd();
			int x=anyo[1];
			if(!x||cur[1]==l)puts("-1");
			else {
				printf("%d\n",max(v[cur[1]],v[LCA(l,x)]));
			}
		}
	}
}