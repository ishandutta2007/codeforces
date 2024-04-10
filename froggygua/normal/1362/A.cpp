#include<iostream>
#include<cstdio>
#include<cstring>
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
int T;
ll a,b;
int main(){
	T=read();
	while(T--){
		a=read(),b=read();
		if(a<b)swap(a,b);
		int cnt=0;
		while(a^b&&!(a&1)&&a){
			a>>=1,++cnt;
		}
		if(a^b){
			printf("-1\n");continue;
		}
		printf("%d\n",cnt?(cnt-1)/3+1:0);
	}
	return 0;
}