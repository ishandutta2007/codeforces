#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int n,ans,now,a[N];
char s[N];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=a[i-1];
		if(s[i]=='R')++a[i];
		else --a[i];
	}
	for(int i=2;i<n;++i){
		if(!a[i]&&1LL*a[i-1]*a[i+1]<0)++ans;
	}
	printf("%d\n",ans);
	return 0;
}