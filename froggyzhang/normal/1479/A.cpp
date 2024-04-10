#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N];
int Query(int x){
	if(a[x])return a[x];
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
void Report(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main(){
	n=read();
	a[0]=a[n+1]=n+1;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(l==r){
			Report(l);
		}
		a[mid]=Query(mid);
		a[mid-1]=Query(mid-1);
		a[mid+1]=Query(mid+1);
		if(a[mid]<a[mid-1]&&a[mid]<a[mid+1]){
			Report(mid);
		}
		if(a[mid]<a[mid+1]){
			r=mid;
		}
		else l=mid+1;
	}
	assert(false);
	return 0;
}