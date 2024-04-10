#include<bits/stdc++.h>
using namespace std;
#define N 233
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
char s[N];
void Solve(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='?'&&isalpha(s[i-1]))s[i]=(s[i-1]=='B'?'R':'B');	
	}
	for(int i=n;i>=1;--i){
		if(s[i]=='?')s[i]=(s[i+1]=='B'?'R':'B');	
	}
	for(int i=1;i<=n;++i){
		putchar(s[i]);
	}
	putchar('\n');
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}