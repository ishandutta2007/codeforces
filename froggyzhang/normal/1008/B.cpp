#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
const int inf=0x3f3f3f3f;
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
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=read();
	}
	int las=inf;
	for(int i=1;i<=n;++i){
		if(max(a[i],b[i])<=las){
			las=max(a[i],b[i]);
		}
		else if(min(a[i],b[i])>las){
			return !printf("NO\n");
		}
		else{
			las=min(a[i],b[i]);
		}
	}
	printf("YES\n");
	return 0;
}