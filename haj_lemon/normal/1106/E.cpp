#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
#define K 210
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int s,t,d,co;}a[N],an[N];
struct seg{int l,r;Info s;}t[N*4];
int m,n,k;
ll dp[N][K],ansn=INF;
bool comp(const Info &a,const Info &b){if (a.co!=b.co) return a.co<b.co;return a.d<b.d;}
void ya(int nu){
	if (t[nu].s.co!=0&&t[nu].l!=t[nu].r){
		t[nu*2].s=t[nu].s;t[nu*2+1].s=t[nu].s;
		t[nu].s=(Info){0,0,0,0};
	}
}
void build(int nu,int l,int r){t[nu].l=l;t[nu].r=r;if (l!=r){build(nu*2,l,(l+r)/2);build(nu*2+1,(l+r)/2+1,r);}}
void add(int nu,int l,int r,Info x){
	ya(nu);
	if (t[nu].l==l&&t[nu].r==r){t[nu].s=x;return ;}
	int mid=(t[nu].l+t[nu].r)/2;
	if (l<=mid) add(nu*2,l,min(mid,r),x);
	if (r>mid) add(nu*2+1,max(mid+1,l),r,x);
}
void work(int nu){
	if (t[nu].l==t[nu].r){an[t[nu].l]=t[nu].s;}
	else{ya(nu);work(nu*2);work(nu*2+1);}
}
int main(){
	read(n);read(m);read(k);
	for (int i=1;i<=k;i++){read(a[i].s);read(a[i].t);read(a[i].d);read(a[i].co);}
	sort(a+1,a+k+1,comp);
	build(1,1,n);
	for (int i=1;i<=k;i++)add(1,a[i].s,a[i].t,a[i]);
	work(1);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++) dp[i][j]=INF;
	dp[0][0]=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<=m;j++){
			if (j<m) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			if (an[i+1].co==0)dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			else dp[an[i+1].d][j]=min(dp[an[i+1].d][j],dp[i][j]+an[i+1].co);
		}
	}
	for (int i=0;i<=m;i++) ansn=min(ansn,dp[n][i]);
	cout<<ansn<<endl;
	return 0;
}