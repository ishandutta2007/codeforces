#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,f[]={0,1,2,3,4,8,12,5,10,15,6,11,13,7,9,14},ff[]={0,2,3,1};
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll tmp=n;
		if(n<=15){
			printf("%lld\n",f[n]);
			continue;
		}
		ll now=0;
		while(tmp)tmp/=4,now++;
		tmp=(n+2)/3;
		ll from=(1ll<<(2*(now-1)))+(n-(1ll<<(2*(now-1))))/3;
		if(n%3==1)printf("%lld\n",from);
		else {
			ll sx=(n-(1ll<<(2*(now-1))))/3;
			ll tmp=(1ll<<(2*now-1));
			ll ii=1;
			while(sx)tmp+=ii*ff[sx%4],sx/=4,ii*=4;
			if(n%3==2)printf("%lld\n",tmp);
			else printf("%lld\n",from^tmp);
		}
	}
}