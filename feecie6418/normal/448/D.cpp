#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int n,m;
long long k;
bool Check(long long mid){
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=min(mid/i,1ll*m);
	return ans>=k;
}
int main() {
	cin>>n>>m>>k;
	long long l=1,r=1ll*n*m,ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(Check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}