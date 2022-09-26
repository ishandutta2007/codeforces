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
int Q,n,m;
bool Solve(){
	int t=n&m;
	n-=t,m-=t;
	if(n>m)return false;
	for(int i=0,k=0;i<=30;++i){
		if(n>>i&1)++k;
		if(m>>i&1)--k;
		if(k<0)return false;
	}
	return true;
}
int main(){
	Q=read();
	while(Q--){
		n=read(),m=read();
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}