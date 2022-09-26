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
int n,m;
int Swap(int i,int j,int n){
	int m=n^((n>>i&1)<<i)^((n>>j&1)<<j);
	m^=((n>>i)&1)<<j;
	m^=((n>>j)&1)<<i;
	return m;
}
int main(){
	n=read();
	n=Swap(0,4,n);
	n=Swap(2,3,n);
	printf("%d\n",n);
	return 0;
}