#include<bits/stdc++.h>
using namespace std;const int N=2e5+7;
int a[N],n,i;long long ans;map<int,long long>mp;
int main(){
	for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",a+i),mp[a[i]-i]+=a[i];
	for(auto&x:mp)ans=max(ans,x.second);
	printf("%lld\n",ans);
}