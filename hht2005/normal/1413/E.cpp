#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	long long a,b,c,d;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(1ll*b*c<a) {
			puts("-1");
			continue;
		}
		int L=1,R=c/d+1;
		while(L<=R) {
			int mid=(L+R)>>1;
			if(d*b*(mid-1)-a<0)L=mid+1;
			else R=mid-1;
		}
		L--;
		printf("%lld\n",a*L-d*b*(L-1)*L/2);
	}
	return 0;
}