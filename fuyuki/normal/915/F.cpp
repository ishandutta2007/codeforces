#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e6+1;
ll ans;
int n,a[N],fa[N],siz[N];
struct node{
	int x,y,w;
	I operator<(const node&u)const{return w<u.w;}
}e[N];
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll merge(int x,int y){
	ll out=1ll*siz[x=find(x)]*siz[y=find(y)];
	return fa[y]=x,siz[x]+=siz[y],out;
}
V input(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",a+i);
	FOR(i,2,n)scanf("%d%d",&e[i].x,&e[i].y);
}
V work(){
	FOR(i,2,n)e[i].w=max(a[e[i].x],a[e[i].y]);
	FOR(i,1,n)siz[fa[i]=i]=1;
	sort(e+2,e+n+1);
	FOR(i,2,n)ans+=1ll*e[i].w*merge(e[i].x,e[i].y);
	FOR(i,2,n)e[i].w=-min(a[e[i].x],a[e[i].y]);
	FOR(i,1,n)siz[fa[i]=i]=1;
	sort(e+2,e+n+1);
	FOR(i,2,n)ans+=1ll*e[i].w*merge(e[i].x,e[i].y);
	cout<<ans;
}
int main(){
	input();
	work();
	return 0;
}