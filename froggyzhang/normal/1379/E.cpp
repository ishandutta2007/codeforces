#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
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
int n,k,f[N],cnt;
bool can(int n,int k){
	if(n<=3)return !k;
	if(n==9&&k==2)return false;
	return k<=n/2-1&&k^(!(bool)(n&(n+1)));
}
inline int Get(int n){
	if(!n)return 0;
	return (1LL*rand()*rand()+rand())%n;
}
int dfs(int n,int k){
	if(n==1){
		return ++cnt;
	}
	if(!k){
		int nl=dfs(n>>1,k);
		int nr=dfs(n>>1,k);
		return f[nl]=f[nr]=++cnt;
	}
	if(n>3&&can(n-2,k-1)){
		int nl=dfs(n-2,k-1);
		int nr=++cnt;
		return f[nl]=f[nr]=++cnt;
	}
	while("MYH AK IOI"){
		int l=Get(n/2)<<1|1,r=n-l-1;
		int c=((l<<1)<=r||(r<<1)<=l);
		int p=Get(k+1-c);
		if(can(l,p)&&can(r,k-p-c)){
			int nl=dfs(l,p);
			int nr=dfs(r,k-p-c);
			return f[nl]=f[nr]=++cnt;
		}
	}
}
int main(){
	n=read(),k=read();
	if(!(n&1)||!can(n,k))puts("NO");
	else{
		srand(time(0));
		puts("YES");
		dfs(n,k);
		for(int i=1;i<=n;++i){
			printf("%d ",f[i]);
		}
	}
	return 0;
}