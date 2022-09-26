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
int T,n,pre0[N],suf0[N],pre1[N],suf1[N];;
char s[N];
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=n;
		for(int i=1;i<=n;++i){
			pre0[i]=pre0[i-1],pre1[i]=pre1[i-1];
			if(s[i]=='0')++pre0[i];
			else ++pre1[i];
		}
		suf0[n+1]=suf1[n+1]=0;
		for(int i=n;i>=1;--i){
			suf0[i]=suf0[i+1],suf1[i]=suf1[i+1];
			if(s[i]=='0')++suf0[i];
			else ++suf1[i];
		}
		for(int i=0;i<=n;++i){
			ans=min(ans,min(n-pre0[i]-suf1[i+1],n-pre1[i]-suf0[i+1]));
		}
		printf("%d\n",ans);
	}
	return 0;
}