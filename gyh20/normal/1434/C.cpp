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
const int M=1e9+7;
int t,a,b,c,d,sum;
signed main(){
	t=read();
	while(t--){
		a=read(),b=read(),c=read(),d=read();
		re int l=0,r=1e10,ans=0;
		while(l<=r){
			re int mid=l+r>>1,ll=1,rr=mid,sss=0;
			while(ll<=rr){
				re int mmid=ll+rr>>1;
				if((mid-mmid)*d>=c)ll=mmid+1;
				else sss=mmid,rr=mmid-1;
			}
			sum=(mid-sss)*b*min(c,d);
			if(sss>1)sum+=(c-(mid-sss)*d)*b;
			if(sum>=a)r=mid-1;
			else l=mid+1,ans=mid;
		}
		re int ll=1,rr=ans,sss=0;
		while(ll<=rr){
			re int mmid=ll+rr>>1;
			if((ans-mmid)*d>=c)sss=mmid,ll=mmid+1;
			else rr=mmid-1;
		}
		if(ans>1e9){
			puts("-1");
			continue;
		}
		sum=a*ans;
		l=0,r=ans;
		re int pos=0;
		while(l<=r){
			re int mid=l+r>>1;
			if(mid*d+c>ans*d)r=mid-1;
			else l=mid+1,pos=mid;
		}
		sum-=pos*c*b;
		re int aa=(0+ans-pos-1)*(ans-pos)/2;
	//	for(re int i=pos+1;i<=ans;++i)sum-=(ans-i)*d*b;
		sum-=aa*d*b;
		printf("%lld\n",sum);
	}
}