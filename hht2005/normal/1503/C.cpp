#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
pair<int,int>a[maxn];
int main() {
	int n,Max=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i].first,&a[i].second);
		ans+=a[i].second;
		a[i].second+=a[i].first;
	}
	sort(a+1,a+n+1);
	Max=a[1].second;
	for(int i=2;i<=n;i++) {
		ans+=max(0,a[i].first-Max);
		Max=max(Max,a[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}