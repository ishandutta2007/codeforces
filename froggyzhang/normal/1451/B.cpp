#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2333
inline int read(){
	int x=0,f=1;
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
int T,n,Q;
char s[N];
void Solve(){
	n=read(),Q=read();
	scanf("%s",s+1);
	while(Q--){
		int l=read(),r=read();
		bool ok=false;
		for(int i=r+1;i<=n;++i){
			if(s[i]==s[r]){
				ok=true;break;
			}
		}
		for(int i=1;i<l;++i){
			if(s[i]==s[l]){
				ok=true;
				break;
			}
		}
		printf(ok?"YES\n":"NO\n");
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}