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
#define N 200050
ll a[N],b[N],s[N];
int n,q;
int main() {
	scanf("%d%d",&n,&q);
	int i;
	ll lst;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	lst=s[n];
	int now=1;
	ll x;
	for(i=1;i<=q;i++) {
		scanf("%lld",&x);
		if(x>=lst) {
			printf("%d\n",n);
			lst=s[n];
			b[now]=0;
			now=1;
		}else {
			int tmp=now;
			lst-=x;
			if(x+b[now]>=a[now]) {
				x-=(a[now]-b[now]);
				b[now]=0;
				int p=upper_bound(s+1,s+n+1,x+s[now])-s-1;
				now=p+1;
				b[now]+=(x-(s[now-1]-s[tmp]));
				printf("%d\n",n-now+1);
			}else {
				b[now]+=x;
				printf("%d\n",n-now+1);
			}
		}
	}
}
/*
******************************
suika
******************************
*/