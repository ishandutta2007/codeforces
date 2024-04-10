#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int sum[maxn],T[maxn],a[maxn];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=n;i>=1;i--) {
		sum[i]=sum[i+1]+!T[a[i]];
		T[a[i]]=1;
	}
	memset(T,0,sizeof(T));
	long long ans=0;
	for(int i=1;i<=n;i++) {
		if(!T[a[i]])ans+=sum[i+1];
		T[a[i]]=1;
	}
	cout<<ans<<endl;
	return 0;
}