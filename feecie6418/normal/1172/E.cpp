#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
	int x,id,dlt;
};
int c[400005][2],fa[400005],si[400005],size[400005],ff[400005],n,m,a[400005];
ll b[400005],ans,si2[400005];
vector<int> g[400005];
vector<P> q[400005];
void Pushup(int x){
	size[x]=si[x]+size[c[x][0]]+1+size[c[x][1]];
}
bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
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
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if((c[y][0]==x)!=(c[z][0]==y))Rotate(x);
			else Rotate(y);
		}
		Rotate(x);
	}
}
int findroot(int x){
	assert(isroot(x));
	while(c[x][0])x=c[x][0];
	return Splay(x),x;
}
void Access(int x){
	int y=0;
	for(;x;y=x,x=fa[x]){
		Splay(x);
		si[x]+=size[c[x][1]]-size[y];
		si2[x]+=1ll*size[c[x][1]]*size[c[x][1]]-1ll*size[y]*size[y];
		c[x][1]=y,Pushup(x);
	}
}
void Link(int x){
	//cout<<"Link:"<<x<<' '<<ans<<endl;
	int y=ff[x];
	Access(x),Splay(x),ans-=si2[x];
	//cout<<"Link2:"<<x<<' '<<ans<<endl;
	Access(y),Splay(y);
	int z=findroot(y);
	ans-=1ll*size[c[z][1]]*size[c[z][1]];
	//cout<<"Link3:"<<x<<' '<<ans<<endl;
	Splay(y),fa[x]=y,si[y]+=size[x],si2[y]+=1ll*size[x]*size[x];
	Pushup(y),Access(x),Splay(z),ans+=1ll*size[c[z][1]]*size[c[z][1]];
	//cout<<"Link4:"<<x<<' '<<ans<<endl;
}
void Cut(int x){
	//cout<<"Cut:"<<x<<' '<<ans<<endl;
	int y=ff[x];
	Access(x),Splay(y);
	int z=findroot(y);
	ans-=1ll*size[c[z][1]]*size[c[z][1]];
	//cout<<"Cut:"<<x<<' '<<y<<' '<<z<<' '<<c[z][1]<<endl;
	//for(int i=1;i<=n+1;i++)printf("c[%d][%d]=%d c[%d][%d]=%d fa[%d]=%d\n",i,0,c[i][0],i,1,c[i][1],i,fa[i]);
	Access(x),Splay(y),c[y][1]=fa[x]=0,Pushup(y);
	//cout<<"Cut:"<<x<<' '<<ans<<endl;
	Access(x),Splay(x),ans+=si2[x];
	Splay(z),ans+=1ll*size[c[z][1]]*size[c[z][1]];
	//cout<<"Cut:"<<x<<' '<<ans<<endl;
}
void dfs(int x,int fa){
	ff[x]=fa;
	for(int y:g[x])if(y^fa)dfs(y,x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),q[a[i]].push_back({i,0,1}),size[i]=1;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),q[a[x]].push_back({x,i,0}),q[y].push_back({x,i,1}),a[x]=y;
	dfs(1,n+1);
	for(int i=1;i<=n;i++)Link(i);
	for(int i=1;i<=n;i++){
		b[0]+=1ll*n*n;
		for(int j=0;j<q[i].size();j++){
			P x=q[i][j];
			ll lst=ans;
			if(x.dlt)Cut(x.x);
			else Link(x.x);
			//cout<<"ANS:"<<ans<<'\n';
			b[x.id]+=ans-lst;
			//cout<<"B:"<<x.id<<' '<<b[x.id]<<endl;
		}
		for(int j=q[i].size()-1;j>=0;j--)if(q[i][j].dlt)Link(q[i][j].x);else Cut(q[i][j].x);
	}
	for(int i=1;i<=m;i++)b[i]+=b[i-1];
	for(int i=0;i<=m;i++)printf("%lld\n",1ll*n*n*n-b[i]);
	return 0;
}