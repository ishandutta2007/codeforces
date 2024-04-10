#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],ld[100005],rd[100005],lu[100005],ru[100005];
int pre[100005],suf[100005],ans=0;
// 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]||i==1)ld[i]=i;else ld[i]=ld[i-1];
		if(a[i]>a[i-1]||i==1)lu[i]=i;else lu[i]=lu[i-1];
	}
	for(int i=n;i;i--){
		if(a[i]<a[i+1]||i==n)rd[i]=i;else rd[i]=rd[i+1];
		if(a[i]>a[i+1]||i==n)ru[i]=i;else ru[i]=ru[i+1];
	}
	for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],max(i-lu[i],i-ld[i]));
	for(int i=n;i>=1;i--)suf[i]=max(suf[i+1],max(ru[i]-i,rd[i]-i));
	for(int i=1;i<=n;i++){
		if(ld[i]==i||rd[i]==i)continue;
		if((i-ld[i])%2==1||(rd[i]-i)%2==1||i-ld[i]!=rd[i]-i)continue;
		if(pre[i-1]>=rd[i]-i||suf[i+1]>=rd[i]-i)continue;
		ans++;
	}
	cout<<ans;
	return 0;
}