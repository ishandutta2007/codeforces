#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int n,a[N],b[N];
int Solve(int *a,int *b){
	static int cnt[N],pos[N];
	for(int i=0;i<=n;++i)cnt[i]=pos[i]=0;
	for(int i=1;i<=n;++i){
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		cnt[(pos[b[i]]-i+n)%n]++;
	}
	int mx=0;
	for(int i=0;i<n;++i){
		mx=max(mx,cnt[i]);
	}
	return mx;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	printf("%d\n",max(Solve(a,b),Solve(b,a)));
	return 0;
}