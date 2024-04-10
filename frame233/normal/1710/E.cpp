#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int n,m,a[N],b[N],p1,p2;bool tag;ll c[N],d[N];
inline ll calc(int x,int y){return 1LL*x*y-(c[x]+d[y])-(tag&&p1<=x&&p2<=y);}
bool check(int mid){
	for(int i=n,p=1;i>=1;--i){
		while(p<=m&&a[i]+b[p]>mid)++p;
		c[i]=m+1-p;
	}
	for(int i=m,p=1;i>=1;--i){
		while(p<=n&&a[p]+b[i]>mid)++p;
		d[i]=n+1-p;
	}
	for(int i=1;i<=n;++i)c[i]+=c[i-1];
	for(int i=1;i<=m;++i)d[i]+=d[i-1];
	ll ans0=0;tag=0;
	for(int x=0,y=0;x<=n;++x){
		while(y<m&&calc(x,y+1)>=calc(x,y))++y;
		ans0=std::max(ans0,calc(x,y));
	}
	ll ans1=0;tag=1;
	for(int x=0,y=0;x<=n;++x){
		while(y<m&&calc(x,y+1)>=calc(x,y))++y;
		ans1=std::max(ans1,calc(x,y));
	}
	return ans1+1!=ans0;
}
int main(){
	read(n,m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	int a1=a[1],b1=b[1];std::sort(a+1,a+n+1,std::greater<int>()),std::sort(b+1,b+m+1,std::greater<int>());
	p1=std::find(a+1,a+n+1,a1)-a,p2=std::find(b+1,b+m+1,b1)-b;
	int l=0,r=a1+b1,mid;while(l<r)mid=(l+r)>>1,check(mid)?r=mid:l=mid+1;
	printf("%d\n",l);
	return 0;
}