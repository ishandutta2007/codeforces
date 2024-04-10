#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define re register
#define int long long
inline int read() {
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0') {
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int t,n,k,num,cnt,ia,l,lst,mn,p;
signed main() {
	t=read();
	while(t--) {
		n=read();
		k=read();
		p=n-1;
		mn=0;
		for(re int i=1; i<=n; ++i) {
			if((1ll<<i)<=p) {
				p-=(1ll<<i);
				mn+=i*(1ll<<i);
			} else {
				mn+=p*i;
				break;
			}
		}
		if(mn>k) {
			puts("NO");
			continue;
		}
		k=n*(n-1)/2-k;
		if(k<0) {
			puts("NO");
			continue;
		}
		ia=0;
		cnt=1;
		lst=0;
		puts("YES");
		for(re int i=1; i<=n; ++i) {
			++cnt;
			for(re int j=1; j<(1ll<<i); ++j) {
				if(cnt>=n) {
					ia=1;
					break;
				}
				if((n-cnt)<=k) {

					k=k-(n-cnt);
					++cnt;
				} else {
					ia=1;
					break;
				}
			}
			if(ia)break;
		}
		if(cnt>n)cnt=n;
		for(re int i=2; i<=cnt; ++i) {
			printf("%lld ",i/2);
		}
		lst=cnt;
		for(re int i=lst+1; i<=n; ++i) {
			if(i==n-k+1)printf("%lld ",i-2);
			else printf("%lld ",i-1);
		}
		putchar('\n');

	}
}