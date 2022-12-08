#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn],b[maxn];
int main() {
	int n,h,m,k,i,Min=1e9,j=-1;
	scanf("%d%d%d%d",&n,&h,&m,&k),m/=2;
	for(i=1;i<=n;i++) {
		scanf("%*d%d",a+i);
		a[i]%=m;
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n&&a[i]+k-1<m;i++) {
		int L=a[i]+1,R=a[i]+k-1,v=upper_bound(a+1,a+n+1,R)-upper_bound(a+1,a+n+1,L-1);
		if(v<Min) {
			Min=v;
			j=a[i];
		}
	}
	for(;i<=n;i++) {
		int L=a[i],R=(a[i]+k)%m,v=upper_bound(a+1,a+n+1,L)-upper_bound(a+1,a+n+1,R-1);
		v=n-v;
		if(v<Min) {
			Min=v;
			j=a[i];
		}
	}
	printf("%d %d\n",Min,(j+k)%m);
	if(j+k-1<m) {
		for(int i=1;i<=n;i++)
			if(b[i]>j&&b[i]<j+k)
				printf("%d ",i);
		puts("");
	} else {
		for(int i=1;i<=n;i++)
			if(b[i]>j||b[i]<(j+k)%m)
				printf("%d ",i);
		puts("");
	}
	return 0;
}