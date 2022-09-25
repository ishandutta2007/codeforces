#include<bits/stdc++.h>
using namespace std;
#define N 233
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
int T,n,k,a[N],ans; 
inline int Roll(){
	for(int i=1;i<n;++i){
		if(a[i]<a[i+1])return ++a[i],i;
	}
	return -1;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		ans=0;
		while(k--){
			ans=Roll();
			if(!~ans)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}