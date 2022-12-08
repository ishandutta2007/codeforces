#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int a[maxn],n,k,ans;
priority_queue<int>q;
signed main() {
	scanf("%lld%lld",&n,&k),k++;
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++)q.push(0);
	for(int i=n;i>=1;i--) {
		int t=q.top();
		q.pop();
		ans+=t;
		q.push(t+a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}