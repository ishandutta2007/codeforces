#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int T,n,c[N],k;
int Solve(){
	for(int i=1;i<=n;++i){
		c[i]=read();
	}
	int ans=n;
	for(int t=1;t<=100;++t){
		int cnt=0;
		int las=-1;
		for(int i=1;;++i){
			if(~las&&(i==n+1||i-las==k)){
				++cnt,las=-1;
			}
			if(i>n)break;
			if(c[i]==t)continue;
			if(!~las)las=i;
		}
		ans=min(ans,cnt);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		printf("%d\n",Solve());
	}
	return 0;
}