/**************************
orz popoqqq
orz wyfcyx
orz jkxing
orz szy
orz xqz
orz GXZlegend
orz CQzhangyu
orz lijinnn
orz Winniechen
***************************/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double f2;
#define mem1(x) memset(x,0,sizeof(x))
#define mem2(x) memset(x,0x3f,sizeof(x))
int fabs(int x){return x>0?x:-x;}
ll a[20],b[20];
int main() {
	int i,j;
	ll ans=0;
	for(i=1;i<=14;i++) {
		scanf("%lld",&a[i]);
		//if(a[i]%2==0) ans+=a[i];
	}
	for(i=1;i<=14;i++) if(a[i]) {
		ll re=0;
		for(j=1;j<=14;j++) b[j]=a[j];
		ll t=a[i]/14,k=a[i]%14;
		b[i]=0;
		if(k==0) {
			for(j=1;j<=14;j++) b[j]+=t;
		}else {
			for(j=1;j<=14;j++) b[j]+=t;
			j=i+1;if(j==15) j=1;
			while(k--) {
				b[j]++;
				j++;
				if(j==15) j=1;
			}
		}
		for(j=1;j<=14;j++) if(b[j]%2==0) re+=b[j];
		ans=max(ans,re);
	}
	printf("%lld\n",ans);
}
/*
******************************
suika
******************************
*/