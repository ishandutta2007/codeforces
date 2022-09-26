#include<bits/stdc++.h>
using namespace std;
#define N 400040
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
bool Solve(){
	a=read(),b=read();
	n=a+b;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]!='?'&&s[n-i+1]!='?'){
			if(s[i]!=s[n-i+1])return false;
		}
	}
	for(int i=1;i<=n;++i){
		if(s[i]!='?')s[n-i+1]=s[i];
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='0')--a;
		else if(s[i]=='1')--b;
	}
	if(a<0||b<0)return false;
	if(n&1 && s[(n+1)/2]=='?'){
		if(a&1)s[(n+1)/2]='0',--a;
		else s[(n+1)/2]='1',--b;
	}
	else if(a&1)return false;
	for(int i=1;i<=n;++i){
		if(s[i]=='?'){
			if(a)s[i]=s[n-i+1]='0',a-=2;
			else s[i]=s[n-i+1]='1',b-=2;
		}
	}
	for(int i=1;i<=n;++i){
		putchar(s[i]);
	}
	putchar('\n');
	return true;
}
int main(){
	T=read();
	while(T--){
		if(!Solve())printf("-1\n");;	
	}
	return 0;
}