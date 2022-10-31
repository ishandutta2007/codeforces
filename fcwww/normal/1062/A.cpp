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
char buf[100000],*p1,*p2;
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd() {
	int x=0; char s=nc();
	while(s<'0'||s>'9') s=nc();
	while(s>='0'&&s<='9') x=(((x<<2)+x)<<1)+s-'0',s=nc();
	return x;
}
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
#undef N
int a[100000],n;
int main() {
	Scape_Goat_Tree::init();
	SA::init();

	// int n;
	// scanf("%d",&n);
	// if(n==1) {
	// 	puts("1 0"); return 0;
	// }
	// int i,ans1=1,t=n,mx=0,mn=1<<30;
	// for(i=2;i*i<=t;i++) {
	// 	if(t%i==0) {
	// 		ans1*=i;
	// 		int cnt=0;
	// 		while(t%i==0) t/=i,cnt++;
	// 		mx=max(mx,cnt);
	// 		mn=min(mn,cnt);
	// 	}
	// }
	// if(t!=1) ans1*=t,mn=min(mn,1),mx=max(mx,1);
	// printf("%d ",ans1);
	// int ans2=0;

	// int x=1;
	// while(x<mx) x<<=1,ans2++;
	// if(mn!=mx) ans2++;
	// printf("%d\n",ans2);
	// return 0;
	scanf("%d",&n);
	int i,now=0,ans=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=0;
	a[n+1]=1000+1;
	for(i=1;i<=n;i++) {
		if(a[i]==a[i-1]+1 && a[i]==a[i+1]-1) {
			now++;
		}else {
			ans=max(ans,now); now=0;
		}
	}
	ans=max(ans,now);
	printf("%d\n",ans);
}