#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
priority_queue<int>q1,q2;
int a[N][N],H[N*N],L[N*N];
signed main() {
	int n,m,k,p;
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",a[i]+j);
	for(int i=1;i<=n;i++) {
		int sum=0;
		for(int j=1;j<=m;j++)
			sum+=a[i][j];
		q1.push(sum);
	}
	for(int j=1;j<=m;j++) {
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i][j];
		q2.push(sum);
	}
	for(int i=1;i<=k;i++) {
		int a=q1.top(),b=q2.top();
		q1.pop(),q2.pop();
		H[i]=a+H[i-1];
		L[i]=b+L[i-1];
		q1.push(a-m*p);
		q2.push(b-n*p);
	}
	long long ans=-1e18;
	for(int i=0;i<=k;i++)
		ans=max(ans,L[i]+H[k-i]-i*(k-i)*p);
	cout<<ans<<endl;
	return 0;
}