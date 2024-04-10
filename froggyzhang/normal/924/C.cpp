#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
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
int n,a[N],b[N];
ll ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=max(a[i]+1,b[i-1]);
	}
	for(int i=n-1;i>=1;--i){
		b[i]=max(b[i],b[i+1]-1);
	}
	for(int i=1;i<=n;++i){
		ans+=b[i]-a[i]-1;
	}
	printf("%lld\n",ans);
	return 0;
}