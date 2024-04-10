#include<bits/stdc++.h>
#define INF 2e9
using namespace std;
int n,k,p,a[2010],b[2010];
bool pan(int x){
	int sum=0;
	for (int i=1,j=1;j<=k;j++){
		if (i<=n&&abs(a[i]-b[j])+abs(b[j]-p)<=x)i++,sum++;
	}
	return (sum==n);
}
int main(){
	cin>>n>>k>>p;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=k;i++)cin>>b[i];
	sort(a+1,a+n+1);sort(b+1,b+k+1);
	long long l=0,r=INF,mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (pan(mid)) r=mid;else l=mid;
	}
	if (pan(l))cout<<l<<endl;else cout<<r<<endl;
	return 0;
}