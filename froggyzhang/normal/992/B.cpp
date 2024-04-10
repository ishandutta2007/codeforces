#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int l,r,x,y,ans;
int main(){
	l=read(),r=read(),x=read(),y=read();
	l=(l-1)/x+1,r=r/x;
	if(y%x)return !printf("0\n");
	y=y/x;
	for(int i=l;1LL*i*i<=y&&i<=r;++i){
		if(y%i!=0)continue;
		int j=y/i;
		if(__gcd(i,j)==1&&j>=l&&j<=r){
			++ans;
			if(i^j)++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}