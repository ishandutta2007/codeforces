#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110],n;
int read() {
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'1';ch=getchar());
	for(;ch>='0'&&ch<='1';ch=getchar())
		x=x<<1|(ch^48);
	return x;
}
int calc(int x) {
	return x+1-(upper_bound(a+1,a+n+1,x)-a-1);
}
signed main() {
	int T;
	scanf("%lld",&T);
	while(T--) {
		int m;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int l=0,r=(1ll<<m)-1,S=r+1-n;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(calc(mid)<S/2+S%2)l=mid+1;
			else r=mid-1;
		}
		for(int i=m-1;i>=0;i--)putchar((l>>i&1)^48);
		puts("");
	}
	return 0;
}