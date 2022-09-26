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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,a[N],pos[N],vis[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			pos[a[i]]=i;
			vis[i]=0;
		}
		vis[n+1]=1;
		int nxt=0;
		bool ok=true;
		for(int i=1;i<=n;++i){
			if(nxt&&pos[i]^nxt){
				printf("No\n");
				ok=false;
				break;
			}
			nxt=pos[i];
			++nxt;
			if(vis[nxt])nxt=0;
			vis[pos[i]]=1;
		}
		if(ok){
			printf("Yes\n");
		}
	}
	return 0;
}