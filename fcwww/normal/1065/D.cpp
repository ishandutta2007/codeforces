#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef double f2;
typedef long double f3;
#define N 100050
#define OUTSIZE 1050
#define rep(n) for(i=1;i<=n;i++)
#define per(n) for(i=n;i;i--)
namespace SA {
	int n,ws[OUTSIZE],wa[OUTSIZE],wb[OUTSIZE],rk[OUTSIZE],height[OUTSIZE],sa[OUTSIZE];
	char w[OUTSIZE];
	void build(int m) {
		int i,j,p,*x=wa,*y=wb;
		rep(m)ws[i]=0;
		rep(n)ws[x[i]=w[i]]++;
		rep(m)ws[i]+=ws[i-1];
		per(n)sa[ws[x[i]]--]=i;
		for(j=1;j<n;j<<=1) {
			for(p=0,i=n;i>n-j;i--) y[++p]=i;
			rep(n)if(sa[i]>j) y[++p]=sa[i]-j;
			rep(m)ws[i]=0;
			rep(n)ws[x[i]]++;
			rep(m)ws[i]+=ws[i-1];
			per(n)sa[ws[x[y[i]]]--]=y[i];
			swap(x,y);
			m=1;
			rep(n)x[sa[i]]=y[sa[i]+j]==y[sa[i+1]+j]&&y[sa[i]]==y[sa[i+1]]?m:m++;
			if(m>n) break;
		}
		rep(n)rk[sa[i]]=i; 
		p=0;
		rep(n)if(rk[i]!=n) {
			j=rk[i]+1;
			for(;w[i+p]==w[sa[j]+p];p++) ;
			height[rk[i]]=p;
			if(p) p--;
		}
	}
	void init() {
		n=6; w[1]='a'; w[2]='b'; w[3]='a'; w[4]='b'; w[5]='b'; w[6]='a';
		build(128);
	}
}
namespace Scape_Goat_Tree {
	#define ls ch[p][0]
	#define rs ch[p][0]
	int ch[OUTSIZE][2],val[OUTSIZE],siz[OUTSIZE],tot[OUTSIZE],ex[OUTSIZE],S[OUTSIZE],V[OUTSIZE],tp,koishi;
	int root,f[OUTSIZE],cnt;
	f2 AL=0.75;
	void pushup(int p) {
		siz[p]=siz[ls]+siz[rs]+ex[p];
		tot[p]=tot[ls]+tot[rs]+1;
	}
	int GG(int p) {
		return tot[p]*AL<max(tot[ls],tot[rs]);
	}
	int newnode(int v) {int p=++cnt; siz[p]=tot[p]=ex[p]=1; val[p]=v; return p;}
	void insert(int &p,int v,int fa) {
		if(!p) {p=newnode(v); f[p]=fa; return ;}
		insert(ch[p][v>val[p]],v,p);
		pushup(p); if(GG(p)) koishi=p;
	}
	void init() {
		insert(root,1,0); insert(root,2,0); insert(root,3,0);
		insert(root,4,0); insert(root,5,0);
	}
	#undef ls
	#undef rs
}
namespace Me {
	
}
#define N 100050
#define mp(x,y) make_pair(x,y)
#define pi pair<int,int>
#define inf 0x3f3f3f3f
struct A {
	int f,g;
	A(){f=g=0;}
	A(int f_,int g_) {f=f_,g=g_;}
	bool operator < (const A &x) const {return f==x.f?g<x.g:f<x.f;} 
	A operator + (const A &x) const {return (A){f+x.f,g+x.g};}
}val[N];
A ans,f[120][3],Dis[11][11][3];
int n,a[12][12],tx[123],ty[123];
int ddx[]={-1,-2,-2,-1,1,2,2,1};
int ddy[]={2,1,-1,-2,-2,-1,1,2};
int head[11][11][3];
struct B {
	int x,y,o;
	B() {x=y=o=0;}
	B(int x_,int y_,int o_) {x=x_,y=y_,o=o_;}
	bool operator <(const B &u) const {return x==u.x?y<u.x:x<u.x;}
}to[N];
priority_queue<pair<A,B> >q;
int cnt,nxt[N];
inline void add(int x,int y,int o1,int z,int w,int o2,A v) {
	to[++cnt]=B(z,w,o2);
	nxt[cnt]=head[x][y][o1];
	head[x][y][o1]=cnt;
	val[cnt]=v;
}
void dij(B st) {
	int x,y,o,i;
	for(x=1;x<=n;x++) for(y=1;y<=n;y++) {
		for(o=0;o<3;o++) {
			Dis[x][y][o]=A(inf,0);
		}
	}
	Dis[st.x][st.y][st.o]=A(0,0);
	q.push(mp(A(0,0),st));
	while(!q.empty()) {
		B t=q.top().second; q.pop();
		x=t.x; y=t.y; o=t.o;
		for(i=head[x][y][o];i;i=nxt[i]) {
			B tt=to[i];
			if(Dis[x][y][o]+val[i]<Dis[tt.x][tt.y][tt.o]) {
				Dis[tt.x][tt.y][tt.o]=Dis[x][y][o]+val[i];
				q.push(mp(A(-Dis[tt.x][tt.y][tt.o].f,-Dis[tt.x][tt.y][tt.o].g),tt));
			}
		}
	}
}
void build() {
	int x,y,o1,dx,dy,i,o2;
	for(x=1;x<=n;x++) {
		for(y=1;y<=n;y++) {
			for(o1=0;o1<3;o1++) {
				if(o1==0) {
					for(i=0;i<8;i++) {
						dx=x+ddx[i],dy=y+ddy[i];
						if(dx>=1&&dx<=n&&dy>=1&&dy<=n) {
							add(x,y,o1,dx,dy,o1,A(1,0));
						}
					}
				}else if(o1==1) {
					for(dx=1;dx<=n;dx++) {
						for(dy=1;dy<=n;dy++) {
							if(abs(dx-x)==abs(dy-y)&&(dx!=x||dy!=y)) {
								add(x,y,o1,dx,dy,o1,A(1,0));
							}
						}
					}
				}else {
					for(i=1;i<=n;i++) {
						dx=x; dy=i;
						if(x!=dx||y!=dy) add(x,y,o1,dx,dy,o1,A(1,0));
						dx=i; dy=y;
						if(x!=dx||y!=dy) add(x,y,o1,dx,dy,o1,A(1,0));
					}
				}
				for(o2=0;o2<3;o2++) {
					if(o1==o2) continue;
					add(x,y,o1,x,y,o2,A(1,1));
				}
			}
		}
	}
}
int main() {
	SA::init(); Scape_Goat_Tree::init();
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&a[i][j]); tx[a[i][j]]=i; ty[a[i][j]]=j;
		}
	}
	build();
	for(i=1;i<=n*n;i++) {
		for(j=0;j<3;j++) {
			f[i][j].f=inf;
		}
	}
	for(i=0;i<3;i++) {
		f[1][i]=A(0,0);
	}
	for(i=1;i<n*n;i++) {
		for(j=0;j<3;j++) {
			dij(B(tx[i],ty[i],j));
			for(k=0;k<3;k++) {
				f[i+1][k]=min(f[i+1][k],f[i][j]+Dis[tx[i+1]][ty[i+1]][k]);
			}
		}
	}
	A ans=A(inf,0);
	for(i=0;i<3;i++) ans=min(ans,f[n*n][i]);
	printf("%d %d\n",ans.f,ans.g);
	// int x,y,o1,z,w,o2;
	// for(i=head[3][2][2];i;i=nxt[i]) {
	// 	printf("to=B(%d,%d,%d), val=A(%d,%d)\n",to[i].x,to[i].y,to[i].o,val[i].f,val[i].g);
	// }
	// while(1) {
	// 	scanf("%d%d",&x,&y);
	// 	printf("%d %d\n",f[x][y].f,f[x][y].g);
	// }
	// while(1) {
	// 	scanf("%d%d%d%d%d%d",&x,&y,&o1,&z,&w,&o2);
	// 	dij(B(x,y,o1));
	// 	printf("%d %d\n",Dis[z][w][o2].f,Dis[z][w][o2].g);
	// }
}