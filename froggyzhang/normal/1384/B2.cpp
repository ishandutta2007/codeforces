#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
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
int T,n,k,L;
int d[N];
inline int Abs(int x){
	return x>=0?x:-x;
}
bool Solve(){
	int now=-k;
	for(int i=1;i<=n;++i){
		if(d[i]>L)return false;
		if(d[i]+k<=L){
			now=-k;
			continue;
		}
		if(Abs(now)+d[i]>L){
			if(now>=0)return false;
			now=-(L-d[i]);
		}
		++now;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read(),L=read();
		for(int i=1;i<=n;++i){
			d[i]=read();
		} 
		printf(Solve()?"Yes\n":"No\n");
	}
	return 0;
}