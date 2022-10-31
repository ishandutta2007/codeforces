#include<bits/stdc++.h>
using namespace std;
#define N 100050
int a[N],n,K,Z,s[N];
void solve() {
	scanf("%d%d%d",&n,&K,&Z);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	Z=min(Z,K/2);
	int ans=0;
	if(K>=n-1) ans=s[n];
	for(i=1;i<n && K;i++) {
		int tt=s[i];
		int tmpK=K,tmpZ=Z,j=0;
		while(tmpK && tmpZ) {
			if(j==0) {
				tt+=a[i+1];
			}else {
				tt+=a[i];
				tmpZ--;
			}
			tmpK--;
			j^=1;
		}
		int pos=i+(j&1);
		int lst=min(n,pos+tmpK);
		//printf("%d %d\n",i,lst);
		tt+=s[lst]-s[pos];
		ans=max(ans,tt);
		K--;
	}
	printf("%d\n",ans);
}
int main() {
	int cas;
	scanf("%d",&cas);
	while(cas--) solve();
}