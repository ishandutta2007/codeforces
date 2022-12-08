#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],f[maxn];
int main() {
	int T,n,k;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		int fl=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			if(a[i]==k)fl=1;
		}
		if(!fl) {
			puts("no");
			continue;
		}
		if(n==1) {
			puts("yes");
			continue;
		}
		fl=0;
		for(int i=1;i<=n;i++) {
			f[i]=max(f[i-1],0);
			if(a[i]>=k)f[i]++;
			else f[i]--;
		}
		for(int i=2;i<=n;i++)
			if(f[i-1]+(a[i]>=k?1:-1)>0)fl=1;
		puts(fl?"yes":"no");
	}
	return 0;
}