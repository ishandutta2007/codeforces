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
bool check(int x){
	int t=sqrt(x)-1;
	while(t*t<x)++t;
	return t*t==x;
}
int T;
int main(){
	T=read();
	while(T--){
		int n=read();
		if((n%2==0&&check(n/2))||(n%4==0&&check(n/4))){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}