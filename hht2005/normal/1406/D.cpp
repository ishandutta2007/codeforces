#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn],d[maxn];
int main() {
	int n,q,l,r,v;;
	long long B=0,C=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=2;i<=n;i++) {
		d[i]=a[i]-a[i-1];
		if(d[i]>0)B+=d[i];
		else C-=d[i];
	}
	printf("%lld\n",max(a[1]-(a[1]-B)/2,(a[1]-B)/2+B));
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d%d",&l,&r,&v);
		if(l==1)a[1]+=v;
		else {
			if(d[l]>0)B-=d[l];
			else C+=d[l];
		}//asdf
		if(r<n) {
			if(d[r+1]>0)B-=d[r+1];
			else C+=d[r+1];
		}
		d[l]+=v;
		d[r+1]-=v;
		if(l>1) {
			if(d[l]>0)B+=d[l];
			else C-=d[l];
		}
		if(r<n) {
			if(d[r+1]>0)B+=d[r+1];
			else C-=d[r+1];
		}
		printf("%lld\n",max(a[1]-(a[1]-B)/2,(a[1]-B)/2+B));
	}
	return 0;
}