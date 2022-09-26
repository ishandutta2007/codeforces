#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
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
int n,H,l,r,Q;
int Solve(){
	int t1=read(),f1=read(),t2=read(),f2=read();
	if(t1==t2)return abs(f1-f2);
	if(f1>r&&f2>r)return abs(t1-t2)+f1-r+f2-r;
	if(f1<l&&f2<l)return abs(t1-t2)+l-f1+l-f2;
	return abs(t1-t2)+abs(f1-f2);
}
int main(){
	n=read(),H=read(),l=read(),r=read(),Q=read();
	while(Q--){	
		printf("%d\n",Solve());
	}
	return 0;
}