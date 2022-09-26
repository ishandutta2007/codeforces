#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 2333
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
int n,k,qwq[N];
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		qwq[read()]^=1;
	}
	int tot=0;
	for(int i=1;i<=k;++i){
		tot+=qwq[i];
	}
	printf("%d\n",n-(tot>>1));
	return 0;
}