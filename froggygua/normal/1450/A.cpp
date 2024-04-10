#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
char s[233];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		sort(s+1,s+n+1);
		for(int i=1;i<=n;++i){
			putchar(s[i]);
		}
		putchar('\n');
	}
	return 0;
}