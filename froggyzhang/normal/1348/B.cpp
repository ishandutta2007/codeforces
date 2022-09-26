#include<iostream>
#include<cstdio>
#include<cstring>
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
int T,n,k,a[N],vis[N],b[N],cnt; 
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(!vis[a[i]])b[++cnt]=a[i],vis[a[i]]=1;
		}
		if(cnt>k){
			printf("%d\n",-1);
			continue;
		}
		while(cnt<k)b[++cnt]=1;
		printf("%d\n",n*k);
		for(int i=1;i<=n*k;++i){
			printf("%d ",b[(i-1)%k+1]);
		}
		printf("\n");
	}
	return 0;
}