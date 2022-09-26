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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,a[N];
void Solve(){
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	printf(a[1]<a[n]?"YES\n":"NO\n");
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}