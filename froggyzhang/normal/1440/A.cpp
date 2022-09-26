#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int T,n,c[2],h;
char s[2333];
int Solve(){
	n=read(),c[0]=read(),c[1]=read(),h=read();
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		int p=s[i]-'0';
		ans+=min(c[p],c[p^1]+h);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}