#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define myhmd 233
#define N 300030
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
int n,H,cnt[N],p[N];
inline int Ask(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	return read();
}
inline int Get(int n){
	return (1LL*rand()*rand()+rand())%n+1;
}
int main(){
	H=read();
	n=(1<<H)-1;
	for(int i=1;i<=420;++i){
		int x=Get(n),y=Get(n),z=Get(n);
		while(y==x)y=Get(n);
		while(x==z||y==z)z=Get(n);
		++cnt[Ask(x,y,z)];
	}
	for(int i=1;i<=n;++i){
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return cnt[i]>cnt[j];});
	for(int i=1;i<=n;++i){
		if(i==p[1]||i==p[2])continue;
		if(Ask(p[1],p[2],i)==i){
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}