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
#define N 2000050
int n,m,ans1[N],ans2[N];
int used[N],tot,a,b;
// inline bool cmp(const int &x,const int &y) {return x>y;}
ll s(int l,int r,int p) {
	if(p>=l&&p<=r) return ll(r+l)*(r-l+1)/2-p;
	return ll(r+l)*(r-l+1)/2;
}
bool check(int mid) {
	int i,la=a,lb=b;
	n=m=0;
	tot++;
	for(i=mid;i;i--) if(la>=i) la-=i,ans1[++n]=i,used[i]=tot;
	for(i=1;i<=100000;i++) {
		if(used[i]!=tot&&lb>=i) {
			lb-=i; ans2[++m]=i;
		}
		if(lb<i) break;
	}
	return n+m>=mid;
}
int main() {
	SA::init();Scape_Goat_Tree::init();
	scanf("%d%d",&a,&b);
	// return Me::main();
	int i,lfta=a,lftb=b,mx=0,mxp=0;
	int l=0,r=100000;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}l--; check(l);
	// for(i=mxp+1;i<=l;i++) if(i!=t) ans2[++m]=i;
	printf("%d\n",n);
	for(i=1;i<=n;i++) printf("%d ",ans1[i]); puts("");
	printf("%d\n",m);
	for(i=1;i<=m;i++) printf("%d ",ans2[i]);
}