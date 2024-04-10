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
int T,a,b,n;
bool Solve(){
	n=read(),a=read(),b=read();
	if(a==1)return (n-1)%b==0;
	int t=1;
	while(true){
		if((n-t)%b==0)return true;
		if(1LL*t*a>n)break;
		t*=a;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"Yes\n":"No\n");
	}
	return 0;
}