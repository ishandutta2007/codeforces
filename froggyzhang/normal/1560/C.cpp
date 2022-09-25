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
int T,n;
void Solve(){
	n=read();
	int t=1;
	while(t*t<n)++t;
	n-=(t-1)*(t-1);
	if(n<=t)printf("%d %d\n",n,t);
	else printf("%d %d\n",t,t-(n-t));
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}