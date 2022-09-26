#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 23333
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
int T,n,p[N],c[N]; 
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			p[i]=read(),c[i]=read();
		}
		bool ok=true;
		for(int i=1;i<=n;++i){
			if(p[i]-p[i-1]<c[i]-c[i-1]||p[i]<p[i-1]||c[i]<c[i-1]){
				printf("NO\n");
				ok=false;
				break;
			}
		}
		if(ok){
			printf("YES\n");
		}
	}
	return 0;
}