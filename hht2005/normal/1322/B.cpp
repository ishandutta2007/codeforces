#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int a[N],c[N];
int main() {
	int n,las=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=25;i++) {
		for(int j=1;j<=n;j++)
			c[j]=a[j]&((1<<i)-1);
		sort(c+1,c+n+1);
		int cnt0=0,cnt1=0;
		for(int j=1;j<=n;j++)
			if(a[j]>>(i-1)&1)cnt1^=1;
			else cnt0^=1;
		if((cnt0*cnt1+las)&1)ans+=1<<(i-1);
		las=0;
		for(int j=1,k=n;j<=n;j++) {
			while(k>=1&&c[j]+c[k]>=(1<<i))k--;
			if(k>j)las=las+(n-k)%2;
			else las=las+(n-j)%2;
		}
	}
	if(las&1)ans+=1<<25;
	printf("%d\n",ans);
	return 0;
}