#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int a[maxn],b[maxn],f[maxn];
int main() {
	int n,k;
	long long A=0,B=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",a+i,b+i);
		A+=a[i],B+=b[i];
	}
	long long ans=A/k+B/k;
	A%=k,B%=k;
	f[0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=2*k;j>=0;j--)
			for(int l=max(1,k-b[i]);l<=j&&l<=a[i]&&l<=k;l++)
				f[j]|=f[j-l];
		for(int j=1;j<=k;j++)f[j]|=f[j+k];
	}
	for(int i=1;i<k;i++)
		if(i<=A&&k-i<=B&&f[i]) {
			ans++;
			break;
		}
	printf("%lld\n",ans);
	return 0;
}