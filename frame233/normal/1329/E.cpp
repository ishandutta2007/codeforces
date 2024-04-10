#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005;typedef long long ll;
ll a[N],n,k;int m;
bool check1(ll mid){
	ll L=0;for(int i=0;i<=m;++i)L+=(a[i]+mid-1)/mid-1;
	return L<=k;
}
bool check2(ll mid){
	ll R=0;for(int i=0;i<=m;++i)R+=a[i]/mid-1;
	return k<=R;
}
struct node{ll l,r;inline bool operator < (const node &o)const{return l<o.l;}}b[N];int pos;
void MAIN(){
	read(n,m,k);
	for(int i=1;i<=m;++i)read(a[i]);
	a[0]=0,a[m+1]=n;for(int i=0;i<=m;++i)a[i]=a[i+1]-a[i];
	ll l=1,r=n,mid;while(l<r)mid=(l+r)>>1,check1(mid)?r=mid:l=mid+1;
	ll R0=l;l=1,r=n;while(l<r)mid=(l+r+1)>>1,check2(mid)?l=mid:r=mid-1;
	ll L0=l;if(L0>R0){assert(0);return puts("0"),void();}
	for(int i=0;i<=m;++i)L0=std::min(L0,a[i]);
	pos=0;
	for(int i=0;i<=m;++i){
		ll x=a[i];
		if((x+R0-1)/R0==x/L0+1){
			b[++pos]={x/((x+R0-1)/R0),(x+x/L0-1)/(x/L0)};
		}
	}
	std::sort(b+1,b+pos+1);ll mx=R0,ans=1e18;b[pos+1].l=L0;
	for(int i=1;i<=pos+1;++i){
		ans=std::min(ans,mx-b[i].l);
		mx=std::max(mx,b[i].r);
	}
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}