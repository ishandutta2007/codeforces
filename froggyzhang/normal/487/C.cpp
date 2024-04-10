#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int inv[N],n;
bool check(int x){
	for(int i=2;i<x;++i){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	n=read();
	if(n==1){
		printf("YES\n");
		printf("1\n");
		return 0;
	}
	if(n==4){
		printf("YES\n");
		printf("1\n3\n2\n4\n");
		return 0;
	}
	if(!check(n))return !printf("NO\n");
	printf("YES\n");
	inv[1]=1;
	for(int i=2;i<n;++i){
		inv[i]=1LL*inv[n%i]*(n-n/i)%n;
	}
	printf("1\n");
	for(int i=2;i<n;++i){
		printf("%lld\n",1LL*i*inv[i-1]%n);
	}
	printf("%d\n",n);
	return 0;
}