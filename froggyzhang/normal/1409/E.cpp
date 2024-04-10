#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200020
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
int T,n,k,a[N],mx[N];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			read();
		}
		sort(a+1,a+n+1);
		int pos=1,ans=0;
		for(int i=1;i<=n;++i){
			while(a[i]-a[pos]>k)++pos;
			mx[i]=max(mx[i-1],i-pos+1);
			ans=max(ans,mx[pos-1]+i-pos+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}