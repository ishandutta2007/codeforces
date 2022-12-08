#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],b[maxn],t[maxn],n;
long long ans;
void Qsort(int l,int r) {
	if(l>=r)return;
	int mid=(l+r)>>1;
	Qsort(l,mid);
	Qsort(mid+1,r);
	int i=l,j=mid+1,cnt=l;
	while(i<=mid||j<=r) {
		if(i<=mid&&(j>r||b[i]<=b[j]))t[cnt++]=b[i++],ans+=j-mid-1;
		else t[cnt++]=b[j++];
	}
	for(int i=l;i<=r;i++)
		b[i]=t[i];
}
long long calc(int x,int p) {
	for(int i=1;i<=n;i++)b[i]=(a[i]^x)&p;
	ans=0;
	Qsort(1,n);
	return ans;
}
int main() {
	int x=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=29,p=0;i>=0;i--) {
		p|=1<<i;
		long long t1=calc(x,p),t2=calc(x^(1<<i),p);
		if(t1>t2)x^=1<<i;
	}
	printf("%lld %d\n",calc(x,(1<<30)-1),x);
	return 0;
}