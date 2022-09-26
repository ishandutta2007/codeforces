#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2020
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
int T,n,a[N],ok[20],pos[N],id[20];
int p[20]={0,2,3,5,7,11,13,17,19,23,29,31};
int main(){
	T=read();
	while(T--){
		n=read();
		int cnt=0;
		memset(ok,0,sizeof(ok));
		for(int i=1;i<=n;++i){
			a[i]=read();
			for(int j=1;j<=11;++j){
				if(a[i]%p[j]==0){
					ok[j]=1,pos[i]=j;
					break;
				}
			}
		}
		for(int i=1;i<=11;++i){
			if(ok[i])id[i]=++cnt;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=n;++i){
			printf("%d ",id[pos[i]]);
		}
		printf("\n");
	}
	return 0;
}