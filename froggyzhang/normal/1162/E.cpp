#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 55
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
int n,a[N],cnt,mn;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	mn=*min_element(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		cnt+=a[i]==mn;
	}
	printf(cnt>n/2?"Bob\n":"Alice\n");
	return 0;
}