#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],sum;
signed main(){
	t=read();
	while(t--){
		n=read(),sum=ans=0,ans=1;
		for(re int i=1;i<=n;++i)a[i]=read(),sum+=a[i],b[i]=0;b[1]=a[1];
		re int s=0;
		if(sum&1)sum>>=1;
		else sum>>=1,--sum;
		for(re int i=n;i>=1;--i){
			s+=a[i];
			if(s<=sum)++ans;
		}
		for(re int i=2;i<=n;++i)b[i]=b[i-2]+a[i];
		re int ss=0;
		for(re int i=1;i<n;++i){
			ss+=a[i];
			if(ss>sum)break;
			re int l=0,r=(n-i-1)/2,pos=0;
			while(l<=r){
				re int mid=l+r>>1;
				if(b[i+mid*2]-b[i]+ss<=sum)pos=i+mid*2,l=mid+1;
				else r=mid-1;
			}
			ans+=(pos-i)/2+1;
		}
		ss=a[n];
		for(re int i=1;i<n-1;++i){
			ss+=a[i];
			if(ss>sum)break;
			re int l=0,r=(n-i-2)/2,pos=0;
			while(l<=r){
				re int mid=l+r>>1;
				if(b[i+mid*2]-b[i]+ss<=sum)pos=i+mid*2,l=mid+1;
				else r=mid-1;
			}
			ans+=(pos-i)/2+1;
		}
		ss=0;
		for(re int i=2;i<n;++i){
			ss+=a[i];
			if(ss>sum)break;
			re int l=0,r=(n-i-1)/2,pos=0;
			while(l<=r){
				re int mid=l+r>>1;
				if(b[i+mid*2]-b[i]+ss<=sum)pos=i+mid*2,l=mid+1;
				else r=mid-1;
			}
			ans+=(pos-i)/2+1;
		}
		ss=a[n];
		for(re int i=2;i<n-1;++i){
			ss+=a[i];
			if(ss>sum)break;
			re int l=0,r=(n-i-2)/2,pos=0;
			while(l<=r){
				re int mid=l+r>>1;
				if(b[i+mid*2]-b[i]+ss<=sum)pos=i+mid*2,l=mid+1;
				else r=mid-1;
			}
			ans+=(pos-i)/2+1;
		}
		printf("%lld\n",ans%998244353);
	}
}