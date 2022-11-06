#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define INF 1000000000
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int n,ro,num;
ll ans;
struct Po{int x,y;}a[N];
struct seg{int ls,rs,su;}t[20000010];
bool c1(const Po &a,const Po &b){if (a.y!=b.y)return a.y>b.y;return a.x<b.x;}
ll p1(ll x){return x*(x+1)/2;}
int que(int nu,int l,int r,int nl,int nr){
	if (!nu||l>r) return 0;
	if (l==nl&&r==nr) return t[nu].su;
	int mid=(nl+nr)/2;
	if (l>mid) return que(t[nu].rs,l,r,mid+1,nr);
	if (r<=mid) return que(t[nu].ls,l,r,nl,mid);
	return que(t[nu].ls,l,mid,nl,mid)+que(t[nu].rs,mid+1,r,mid+1,nr);
}
void add(int &nu,int we,int l,int r){
	if (!nu) nu=++num;
	if (l==r){t[nu].su=1;return ;}
	int mid=(l+r)/2;
	if (we<=mid) add(t[nu].ls,we,l,mid);
	else add(t[nu].rs,we,mid+1,r);
	t[nu].su=t[t[nu].ls].su+t[t[nu].rs].su;
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){read(a[i].x);read(a[i].y);}
	sort(a+1,a+n+1,c1);
	for (int l=1,r=0;l<=n;l=r+1){
		while (a[r+1].y==a[l].y)r++;
		for (int i=l;i<=r;i++){
			if (i==l)ans-=p1(que(ro,1,a[i].x-1,1,INF));
			if (i==r) ans-=p1(que(ro,a[i].x+1,INF,1,INF));
			else ans-=p1(que(ro,a[i].x+1,a[i+1].x-1,1,INF));
			add(ro,a[i].x,1,INF);
		}
		ans+=p1(que(ro,1,INF,1,INF));
	}
	cout<<ans<<endl;
	return 0;
}