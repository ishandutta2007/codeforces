#include<bits/stdc++.h>
using namespace std;
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
int x;
int main(){
	while(true){
		printf("next 0\n");
		fflush(stdout);
		x=read();
		for(int i=1;i<=x;++i)read();
		printf("next 0 1\n");
		fflush(stdout);	
		x=read();
		for(int i=1;i<=x;++i)read();
		if(x==2)break;
	}
	while(true){
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		fflush(stdout);
		x=read();
		for(int i=1;i<=x;++i)read();
		if(x==1)break;	
	}
	printf("done\n");
	fflush(stdout);
	return 0;
}