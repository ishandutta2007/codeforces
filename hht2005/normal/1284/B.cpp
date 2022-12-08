#include<bits/stdc++.h>
using namespace std;
int c[100010],mi[100010],mx[100010],a[100010],f[100010];
int main() {
	int n,k,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&k);
		mi[i]=1e9;
		mx[i]=-1e9;
		for(int j=1;j<=k;j++) {
			scanf("%d",a+j);
			if(j!=1&&a[j]>a[j-1])f[i]=1;
			mi[i]=min(mi[i],a[j]);
			mx[i]=max(mx[i],a[j]);
		}////////////////////
		if(!f[i])c[++cnt]=mx[i];
	}/////////////////
	sort(c+1,c+1+cnt);////////////////
	long long ans=0;
	for(int i=1;i<=n;i++)
		if(f[i])ans+=n;
		else ans+=n-(upper_bound(c+1,c+cnt+1,mi[i])-c)+1;
	cout<<ans<<endl;
	return 0;
}