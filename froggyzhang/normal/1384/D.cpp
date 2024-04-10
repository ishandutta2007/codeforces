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
int T,n,a[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=30;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if((a[j]>>i)&1)++cnt;
		}
		if(!(cnt&1))continue;
		int res=n-cnt;
		cnt%=4;
		if(cnt==1){
			printf("WIN\n");
			return;
		}
		else{
			printf(res&1?"WIN\n":"LOSE\n");
			return;
		}
	}
	printf("DRAW\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}