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
int n,ans;
int main(){
	n=read();
	for(int i=1;i*i<=n;++i){
		if(n%i==0){
			++ans;
			if(i*i!=n)++ans;
		}
	}
	printf("%d\n",ans-1);
	return 0;
}