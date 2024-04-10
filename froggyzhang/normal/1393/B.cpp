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
int cnt[N],n,m; 
int t0,t1;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		++cnt[x];
		if(!(cnt[x]&1))++t0;
		if(!(cnt[x]&3))++t1;
	}
	m=read();
	for(int i=1;i<=m;++i){
		char opt[3];
		scanf("%s",opt+1);
		int x=read();
		if(opt[1]=='+'){
			++cnt[x];
			if(!(cnt[x]&1))++t0;
			if(!(cnt[x]&3))++t1;
		}
		else{
			if(!(cnt[x]&1))--t0;
			if(!(cnt[x]&3))--t1;
			--cnt[x];
		}
		if(t1&&t0>=4){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}