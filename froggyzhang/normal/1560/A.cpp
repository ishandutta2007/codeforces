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
int a[1010],an,T;
inline bool check(int x){
	if(x%3==0||x%10==3)return false;
	return true;
}
int main(){
	for(int i=1;an<1000;++i){
		if(check(i))a[++an]=i;	
	}
	T=read();
	while(T--)printf("%d\n",a[read()]);
	return 0;
}