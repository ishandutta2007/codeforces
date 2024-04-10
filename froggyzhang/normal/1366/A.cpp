#include<iostream>
#include<cstdio>
#include<cstring>
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
int T,a,b;
int main(){
	T=read();
	while(T--){
		a=read(),b=read();
		if(a<b)swap(a,b);
		if(b<=a-b){
			printf("%d\n",b);
		}
		else{
			int ans=a-b;
			a-=(ans<<1),b-=ans;
			printf("%d\n",ans+a/3*2+(a%3==2));
		}
	}
	return 0;
}