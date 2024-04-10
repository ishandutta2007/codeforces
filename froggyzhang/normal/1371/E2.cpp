#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int n,p,a[N];
inline bool check(int x){
	for(int i=0,j=1;i<n;++i){
		while(j<=n&&a[j]<=i+x)++j;
		if((j-1-i)%p==0)return false;	
	}
	return true;
}
int main(){
	n=read(),p=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int L=1;
	for(int i=1;i<=n;++i){
		L=max(L,a[i]-(i-1));
		if(a[i]==a[n])break;
	}
	int l=L,r=L+p+1,R=L-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			R=mid,l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%d\n",R-L+1);
	for(int i=L;i<=R;++i){
		printf("%d ",i);
	}
	return 0;
}