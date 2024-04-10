#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=200005;typedef long long ll;
int a[N],b[N],m,n,t[N],rev1[N],rev2[N],ans[N];ll c[N],d[N];
inline void upd(int l,int r,ll C){
	if(l>r)return;
	if(r<0)l+=n,r+=n;
	if(l<0)d[l+n]+=C,d[n]-=C,d[0]+=C,d[r+1]-=C;
	else d[l]+=C,d[r+1]-=C;
}
int main(){
	read(m,n);
	for(int i=0;i<n;++i)read(a[i]),--a[i];
	for(int i=0;i<n;++i)read(b[i]),--b[i];
	std::iota(t,t+n,0),std::sort(t,t+n,[&](int x,int y){return a[x]<a[y];});for(int i=0;i<n;++i)rev1[i]=t[i];
	std::iota(t,t+n,0),std::sort(t,t+n,[&](int x,int y){return b[x]<b[y];});for(int i=0;i<n;++i)rev2[i]=t[i];
	std::sort(a,a+n),std::sort(b,b+n);
	for(int i=0;i<n;++i){
		int j=(a[i]+m/2)%m;
		if(j>=a[i]){
			int l=std::lower_bound(b,b+n,a[i])-b,r=std::upper_bound(b,b+n,j)-b-1;
			upd(l-i,r-i,-a[i]),upd(r-i+1,n-1-i,m+a[i]),upd(-i,l-1-i,a[i]);
		}
		else{
			int l=std::upper_bound(b,b+n,j)-b,r=std::lower_bound(b,b+n,a[i])-b-1;
			upd(l-i,r-i,a[i]),upd(r-i+1,n-1-i,-a[i]),upd(-i,l-1-i,m-a[i]);
		}
	}
	for(int i=1;i<n;++i)d[i]+=d[i-1];
	for(int i=0;i<n;++i)c[i]=d[i],d[i]=0;
	for(int i=0;i<n;++i){
		int j=(b[i]-m/2+m)%m;
		if(j>b[i]){
			int l=std::upper_bound(a,a+n,b[i])-a,r=std::lower_bound(a,a+n,j)-a-1;
			upd(l-i,r-i,-b[i]),upd(r-i+1,n-1-i,b[i]),upd(-i,l-1-i,b[i]);
		}
		else{
			int l=std::lower_bound(a,a+n,j)-a,r=std::upper_bound(a,a+n,b[i])-a-1;
			upd(l-i,r-i,b[i]),upd(r-i+1,n-1-i,-b[i]),upd(-i,l-1-i,-b[i]);
		}
	}
	for(int i=1;i<n;++i)d[i]+=d[i-1];
	d[n]=d[0];for(int i=0;i<n;++i)c[i]+=d[n-i];
	ll mn=1e18;int p=-1;for(int i=0;i<n;++i)if(c[i]<mn)mn=c[i],p=i;
	for(int i=0;i<n;++i)ans[rev1[i]]=rev2[(i+p)%n];
	printf("%lld\n",mn);for(int i=0;i<n;++i)printf("%d%c",ans[i]+1," \n"[i+1==n]);
	return 0;
}