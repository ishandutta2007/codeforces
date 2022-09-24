#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const double pi=acos(-1);
struct point{int x,y,to,fr;}a[2005],b[2005];
ll Dot(point x,point y){return 1ll*x.x*y.x+1ll*x.y*y.y;}
ll Cross(point x,point y){return 1ll*x.x*y.y-1ll*x.y*y.x;}
ll Dis(point x,point y){return 1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y);}
int sgn(ll x){return x>0?1:(x==0?0:-1);}
point operator +(point x,point y){return {x.x+y.x,x.y+y.y};}
point operator -(point x,point y){return {x.x-y.x,x.y-y.y};}
int mny=1e9,mnx=1e9,mnp=0;
int fa[2005],n,m,pl[2005],tot,tmp[2005];
pr ans[100005];
bool cmp(point x,point y){
	return Cross(x-a[mnp],y-a[mnp])>0;
}
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Swap(int x,int y){
	ans[++tot]=pr(x,y);
	swap(pl[x],pl[y]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].to,a[i].fr=i,pl[i]=a[i].to;
		if(a[i].to==i)continue;
		if(a[i].y<mny)mny=a[i].y,mnx=a[i].x,mnp=i;
		else if(a[i].y==mny&&a[i].x<mnx)mnx=a[i].x,mnp=i;
	}
	if(!mnp)return puts("0"),0;
	for(int i=1;i<=n;i++){
		if(a[i].to==i)continue;
		if(i!=mnp)b[++m]=a[i],fa[gf(a[i].to)]=gf(a[i].fr);
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<m;i++){
		int x=gf(pl[b[i].fr]),y=gf(pl[b[i+1].fr]);
		if(x!=y)Swap(b[i].fr,b[i+1].fr),fa[x]=y;
	}
	int x=pl[mnp];
	while(x!=mnp)tmp[++tmp[0]]=x,x=pl[x];
	for(int i=1;i<=tmp[0];i++)Swap(mnp,tmp[i]);
	cout<<tot<<'\n';
	for(int i=1;i<=tot;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	for(int i=1;i<=n;i++)assert(pl[i]==i);
}