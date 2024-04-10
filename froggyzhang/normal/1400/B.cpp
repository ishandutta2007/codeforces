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
int T;
int main(){
	T=read();
	while(T--){
		int A=read(),B=read();
		int n1=read(),n2=read();
		int p1=read(),p2=read();
		if(p1>p2)swap(n1,n2),swap(p1,p2);
		int ans=0;
		for(int i=0;i<=n1;++i){
			if(A<0)break;
			int h=A/p2;
			h=min(h,n2);
			if(B<=1LL*(n1-i)*p1){
				ans=max(ans,i+h+B/p1);
			}
			else{
				ans=max(ans,n1+h+min(n2-h,(B-(n1-i)*p1)/p2));
			}
			A-=p1;
		}
		printf("%d\n",ans);
	}
	return 0;
}