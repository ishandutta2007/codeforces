#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n;
#define Maxn 100010

struct Point{
	int x,y,id;
	double ang(){return atan2(y,x);}
}p[Maxn];
int a[Maxn];
bool cmp(Point b,Point c){return b.ang()<c.ang();}

int fa[Maxn];
int getroot(int x){
	if(fa[x]!=x)fa[x]=getroot(fa[x]);
	return fa[x];
}

pii ed[Maxn<<1];int cnt=0;
Point q[Maxn];

int main(){
	rd(n);
	int at=0;
	rep(i,1,n){
		p[i].id=i;
		rd(p[i].x);rd(p[i].y);rd(a[i]);
		if(a[i]!=i)at=i;
	}
	if(at==0){
		puts("0");
		return 0;
	}
	swap(p[at],p[1]);
	rep(i,2,n){
		p[i].x-=p[1].x;p[i].y-=p[1].y;
	}
	sort(p+2,p+n+1,cmp);
	rep(i,2,n-1)
		if(p[i+1].ang()-p[i].ang()>acos(-1.0)){
			int at=1;
			rep(j,i+1,n)q[++at]=p[j];rep(j,2,i)q[++at]=p[j];
			rep(j,2,n)p[j]=q[j];
			break;
		}
	rep(i,1,n)
		if(!fa[i]){
			int u=i;
			while(!fa[u]){
				fa[u]=i;
				u=a[u];
			}
		} 
	rep(i,2,n-1){
		int x=p[i].id,y=p[i+1].id;
		int fx=getroot(x),fy=getroot(y);
		if(fx!=fy){
			swap(a[x],a[y]);
			ed[++cnt]=pii(x,y);
			fa[fx]=fy;
		}
	}
	int u=p[1].id;
	while(a[u]!=u){
		int y=a[u];
		ed[++cnt]=pii(u,a[u]);
		swap(a[u],a[y]);
	}
	printf("%d\n",cnt);
	rep(i,1,cnt)printf("%d %d\n",ed[i].FR,ed[i].SE);
	return 0;
}