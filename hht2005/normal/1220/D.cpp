#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
long long a[maxn];
int cnt[65],p[maxn];
int main() {
	int n,mx=0,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		long long x=a[i];
		while(!(x&1)) {
			x>>=1;
			p[i]++;
		}
		cnt[p[i]]++;
	}
	for(int i=0;i<=64;i++)
		if(cnt[i]>mx)
			mx=cnt[ans=i];
	printf("%d\n",n-mx);
	for(int i=1;i<=n;i++)
		if(p[i]!=ans)printf("%lld ",a[i]);
	return 0;
}