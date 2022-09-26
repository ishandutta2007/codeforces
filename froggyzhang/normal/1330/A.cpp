#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
#define N 233
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
int T,n,x,a[N]; 
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i){
			int x=read();
			a[x]=1;
		}
		int u=1;
		while(a[u])++u;
		while(x--){
			++u;
			while(a[u])++u;
		}
		printf("%d\n",u-1);
	}
	return 0;
}