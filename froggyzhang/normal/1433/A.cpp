#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int T,n;
const int d[5]={0,1,3,6,10};
int main(){
	T=read();
	while(T--){
		n=read();
		int x=n%10,t=0;
		while(n)++t,n/=10;
		printf("%d\n",(x-1)*10+d[t]);
	}
	return 0;
}