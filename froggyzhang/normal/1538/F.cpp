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
int T,l,r;
inline int Solve(int x){
	int ans=0;
	while(x)ans+=x,x/=10;
	return ans;
}
int main(){
	T=read();
	while(T--){
		l=read(),r=read();
		printf("%d\n",Solve(r)-Solve(l));
	}
	return 0;
}