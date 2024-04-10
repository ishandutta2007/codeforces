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
int T,n,m;
int a[N][2][2];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			for(int x=0;x<2;++x){
				for(int y=0;y<2;++y){
					a[i][x][y]=read();
				}
			}
		}
		if(m&1){
			printf("NO\n");
			continue;
		}
		bool ok=false;
		for(int i=1;i<=n;++i){
			if(a[i][0][1]==a[i][1][0]){
				ok=true;
				break;
			}
		}
		printf(ok?"YES\n":"NO\n");
	}
	return 0;
}