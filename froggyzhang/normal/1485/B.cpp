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
int n,Q,k,a[N];
int main(){
	n=read(),Q=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	while(Q--){
		int l=read(),r=read();
		printf("%d\n",a[r]-a[l]+k+1-(r-l+1)*2);
	}
	return 0;
}