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
int T,n,x;
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;++i){
			int d=read();
			if(d&1)++cnt1;
			else ++cnt0;
		}
		if(n==x){
			printf((cnt1&1)?"Yes\n":"No\n");
		}
		else{
			if(cnt0)printf(cnt1?"Yes\n":"No\n");
			else printf(x&1?"Yes\n":"No\n");
		}
	}
	return 0;
}