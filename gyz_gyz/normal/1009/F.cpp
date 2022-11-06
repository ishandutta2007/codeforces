#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000010
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
struct pr{int x,y;}prs;
operator <(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;else return x.x>y.x;
}
int n,x,y,u,tot,st[N],ed[N],nt[N*2],p[N*2],v[N],r[N],h[N],an[N];
set<pr>a[N],b[N];
set<pr>::iterator it,itt;
void lk(int x,int y){
	if(!st[x])st[x]=++tot;else nt[ed[x]]=++tot;
	ed[x]=tot;p[tot]=y;
}
void hb(int x,int y){
	for(it=a[y].begin();it!=a[y].end();it++){
		prs.x=(*it).x;prs.y=0;
		itt=a[x].lower_bound(prs);
		if((itt!=a[x].end())&&((*itt).x==(*it).x)){a[x].erase(itt);
			prs=*itt;prs.x=prs.y;prs.y=(*it).x;
			b[x].erase(b[x].lower_bound(prs));
			prs.y=prs.x+(*it).y;prs.x=(*it).x;
		}else prs=*it;
		a[x].insert(prs);
		u=prs.x;prs.x=prs.y;prs.y=u;
		b[x].insert(prs);
	}
}
void f(int x){v[x]=1;r[x]=x;
	prs.x=h[x];prs.y=1;a[x].insert(prs);
	prs.x=1;prs.y=h[x];b[x].insert(prs);
	for(int i=st[x];i;i=nt[i])if(!v[p[i]]){
		h[p[i]]=h[x]+1;f(p[i]);
		if(a[r[x]].size()<a[r[p[i]]].size()){
			hb(r[p[i]],r[x]);r[x]=r[p[i]];
		}else hb(r[x],r[p[i]]);	
	}
	an[x]=(*b[r[x]].begin()).y-h[x];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		lk(x,y);lk(y,x);
	}
	f(1);
	rep(i,1,n)printf("%d\n",an[i]);
}