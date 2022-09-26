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
int T,n,a[N],vis[N];
void Solve(){
	int res=n-1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=(n<<1);++i){
		if(!res)break;
		if(vis[i])continue;
		for(int j=i+1;j<=(n<<1);++j){
			if(!((a[i]&1)^(a[j]&1))){
				vis[i]=vis[j]=1;
				printf("%d %d\n",i,j);
				--res;
				break;
			}
		}
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=(n<<1);++i){
			a[i]=read();
		} 
		Solve();
	}
	return 0;
}