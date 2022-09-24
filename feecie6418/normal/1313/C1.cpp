#include<bits/stdc++.h>
using namespace std;
int n,a[1005],maxp;
long long maxx=0,s=0;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	int now;
	for(int i=1; i<=n; i++) {
		s=a[i];
		now=a[i];
		for(int j=i-1; j>0; j--) {
			s+=(now=min(now,a[j]));
		}
		now=a[i];
		for(int j=i+1; j<=n; j++) {
			s+=(now=min(now,a[j]));
		}
		if(s>maxx)maxx=s,maxp=i;
	}
	now=a[maxp];
	for(int j=maxp-1; j>0; j--) {
		now=a[j]=min(now,a[j]);
	}
	now=a[maxp];
	for(int j=maxp+1; j<=n; j++) {
		now=a[j]=min(now,a[j]);
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}