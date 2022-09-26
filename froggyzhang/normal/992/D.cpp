#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
typedef long long ll;
const ll mx=2e18;
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
int n,k,a[N],p[N];
ll s[N],ans;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	p[n]=n+1;
	for(int i=n-1;i>=1;--i){
		if(a[i+1]^1)p[i]=i+1;
		else p[i]=p[i+1];
	}
	for(int i=1;i<=n;++i){
		ll now=1;
		for(int j=i;j<=n;j=p[j]){
			if(now>mx/a[j])break;
			now*=a[j];
			if(now==k*(s[j]-s[i-1]))++ans;
			else if(now%k==0){
				ll t=now/k;
				if(s[j]-s[i-1]<=t&&s[p[j]-1]-s[i-1]>=t)++ans;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}