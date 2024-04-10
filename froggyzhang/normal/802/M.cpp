#include<bits/stdc++.h>
using namespace std;
#define N 2222
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
int n,k,a[N],ans;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	nth_element(a+1,a+k,a+n+1);
	for(int i=1;i<=k;++i){
		ans+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}