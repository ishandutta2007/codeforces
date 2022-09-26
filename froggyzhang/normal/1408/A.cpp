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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
#define N 233
int T,n,a[N],b[N],c[N],p[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	for(int i=1;i<=n;++i){
		c[i]=read();
	}
	p[1]=a[1];
	for(int i=2;i<n;++i){
		p[i]=(a[i]==p[i-1]?b[i]:a[i]);
	}
	p[n]=(p[n-1]==a[n]||p[1]==a[n]?(p[n-1]==b[n]||p[1]==b[n]?c[n]:b[n]):a[n]);
	for(int i=1;i<=n;++i){
		printf("%d ",p[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}