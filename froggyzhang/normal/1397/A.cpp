#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1010
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
int T,n,cnt[30];
char s[N];
bool Solve(){
	n=read();
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int m=strlen(s+1);
		for(int j=1;j<=m;++j){
			++cnt[s[j]-'a'];
		}
	}
	for(int i=0;i<26;++i){
		if(cnt[i]%n)return false;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}