#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000000
#define inf 1000000000
#define mo 1000000007
using namespace std;
int n,m,s,t,x,tot,an1,an2;bool p1[N],p2[N];
int st[N],ed[N],nt[N],fr[N],p[N],w[N],nw[N],d[N],dl[N];
struct pr{int x,y;}a[N],b[N];
bool cmp1(pr x,pr y){
	if(x.y==y.y)return x.x<y.x;return x.y<y.y;
}
bool cmp2(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;return x.x<y.x;
}
void lk(int x,int y,int z){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;w[tot]=z;
	if(!st[y])st[y]=++tot;else nt[ed[y]]=++tot;
	ed[y]=tot;p[tot]=x;w[tot]=0;
}
bool dfs(int x){
	if(x==n*2+2)return 1;
	for(;nw[x];nw[x]=nt[nw[x]])
		if(w[nw[x]]&&d[p[nw[x]]]==d[x]+1&&dfs(p[nw[x]])){
			w[nw[x]]--;w[nw[x]^1]++;return 1;
		}
	return 0;
}
int main(){
	scanf("%d",&n);tot=1;
	rep(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	rep(i,1,n)if(a[i].y==a[i-1].y)lk(1,i+1,1);else p1[i]=1,an1++;
	rep(i,1,n)if(b[i].x==b[i-1].x)lk(i+n+1,n*2+2,1);else p2[i]=1,an2++;
	rep(i,1,n)if(!p1[i])rep(j,1,n)if(!p2[j]&&
		a[i-1].x<b[j].x&&a[i].x>b[j].x&&b[j-1].y<a[i].y&&b[j].y>a[i].y)lk(i+1,j+n+1,n);
	for(;;){
		rep(i,1,n*2+2)d[i]=0,nw[i]=st[i];
		for(s=t=dl[1]=d[1]=1;s<=t;s++)
			for(int i=st[dl[s]];i;i=nt[i])if(w[i]&&!d[p[i]]){
				dl[++t]=p[i];d[p[i]]=d[dl[s]]+1;
			}
		if(!d[n*2+2])break;while(dfs(1));
	}
	rep(i,1,n){
		if(!p1[i]&&!d[i+1])p1[i]=1,an1++;
		if(!p2[i]&&d[i+n+1])p2[i]=1,an2++;
	}
	printf("%d\n",an1);x=1;
	rep(i,2,n)if(p1[i]){
		printf("%d %d %d %d\n",a[x].x,a[x].y,a[i-1].x,a[i-1].y);x=i;
	}
	printf("%d %d %d %d\n",a[x].x,a[x].y,a[n].x,a[n].y);
	printf("%d\n",an2);x=1;
	rep(i,2,n)if(p2[i]){
		printf("%d %d %d %d\n",b[x].x,b[x].y,b[i-1].x,b[i-1].y);x=i;
	}
	printf("%d %d %d %d\n",b[x].x,b[x].y,b[n].x,b[n].y);
}