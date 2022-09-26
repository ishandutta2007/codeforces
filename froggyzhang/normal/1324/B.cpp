#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 5050
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
int T,n,a[N],vis[N];
int main(){
	T=read();
	while(T--){
		n=read();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		bool ok=false;
		for(int i=3;i<=n;i++){
			vis[a[i-2]]=1;
			if(vis[a[i]]){
				printf("YES\n");
				ok=true;
				break;
			}
		}
		if(!ok){
			printf("NO\n");
		}
	}
	return 0;
}