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
int n;
ll k,x,a[N],b[N];
int main(){
	n=read(),k=read(),x=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		b[i]=a[i+1]-a[i];
	}
	sort(b+1,b+n);
	for(int i=1;i<=n;++i){
		if(i==n||k<max(0LL,b[i]-1)/x){
			printf("%d\n",n-i+1);
			break;
		}
		k-=max(0LL,b[i]-1)/x;	
	}
	return 0;
}