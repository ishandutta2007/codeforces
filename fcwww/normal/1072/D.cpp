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
#undef N
#define pi pair<int,int>
#define inf 0x3f3f3f3f
#define N 2070
char mp[2050][2050];
int f[2050][2050],n,K,ans[N<<1],vis[N][N];
struct A {
	int x,y;
	bool operator < (const A &u) const {return x<u.x;}
};
struct B {
	int first;
	A second;
	B() {}
	B(int f,A s) {first=f; second=s;}
	bool operator < (const B &x) const {
		return second.x+second.y==x.second.x+x.second.y ? first>x.first : second.x+second.y>x.second.x+x.second.y;
	}
};
priority_queue<B>q;
void kuo(int x,int y) {
	if(vis[x][y])return ;
	vis[x][y]=1;
	q.push(B(min(mp[x+1][y],mp[x][y+1]),(A){x,y}));
}
int main() {
	SA::init();Scape_Goat_Tree::init();
	// return Me::main();
	scanf("%d%d",&n,&K);
	int i,j;
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(i=0;i<=n+1;i++) mp[i][0]=mp[0][i]=mp[n+1][i]=mp[i][n+1]='z'+1;
	memset(f,0x3f,sizeof(f));
	f[1][1]=mp[1][1]!='a';
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(i==1&&j==1) continue;
			f[i][j]=min(f[i-1][j],f[i][j-1])+(mp[i][j]!='a');
		}
	}
	int mx=0;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(f[i][j]<=K&&i+j>mx) mx=i+j;
	int now=mx-1;
	for(i=1;i<=now;i++) printf("a"),ans[i]='a';
	now++;
	if(now==2*n) return 0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(f[i][j]<=K&&i+j==mx) {
				q.push(B(min(mp[i+1][j],mp[i][j+1]),(A){i,j}));
			}
		}
	}

	if(K==0&&f[1][1]==1) {
		now=2; ans[1]=mp[1][1]; printf("%c",mp[1][1]);
		q.push(B(min(mp[1][2],mp[2][1]),(A){1,1}));
	}
	while(!q.empty()) {
		B x=q.top(); q.pop();
		A p=x.second;
		int val=x.first;
		if(p.x==n&&p.y==n) return 0;
		if(val=='z'+1) continue;
		if(p.x+p.y==now) {
			ans[now]=val;
			// printf("\%d\n",val);
			printf("%c",val);
			now++;
			if(now==2*n) return 0;
			i=p.x; j=p.y;
			if(mp[i][j+1]<=val&&j+1<=n) {
				kuo(i,j+1);
			}
			if(mp[i+1][j]<=val&&i+1<=n) {
				kuo(i+1,j);
			}
		}else if(p.x+p.y==now-1&&ans[now-1]==val) {
			i=p.x; j=p.y;
			if(mp[i][j+1]<=val&&j+1<=n) {
				kuo(i,j+1);
			}
			if(mp[i+1][j]<=val&&i+1<=n) {
				kuo(i+1,j);
			}
		}
	}
	return 0;
}