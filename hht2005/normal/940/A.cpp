#include<bits/stdc++.h>
using namespace std;
int a[110];
int main() {
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=n-1;
	for(int i=1;i<=n;i++) {
		ans=min(ans,int(i-1+n-(upper_bound(a+1,a+1+n,a[i]+d)-a)+1));
	}
	cout<<ans<<endl;
	return 0;
}