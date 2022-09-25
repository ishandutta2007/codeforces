#include<bits/stdc++.h>
using namespace std;
#define N 123
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
int T,n,a,b;
char s[N];
void Solve(){
	n=read(),a=read(),b=read();
	scanf("%s",s+1);
	if(b>=0){
		printf("%d\n",n*(a+b));
		return;
	}
	int t=1;
	for(int i=1;i<n;++i){
		if(s[i]^s[i+1])++t;
	}
	printf("%d\n",n*a+(t/2+1)*b);
}
int main(){
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}