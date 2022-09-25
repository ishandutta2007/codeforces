#include<bits/stdc++.h>
using namespace std;
#define N 2333
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
int T,n,a[N],st[N],top;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	top=0;
	for(int i=1;i<=n;++i){
		if(a[i]==1)st[++top]=1;
		else{
			while(st[top]!=a[i]-1)--top;
			++st[top];	
		}
		for(int j=1;j<=top;++j){
			printf("%d%c",st[j],j==top?'\n':'.');
		}
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}