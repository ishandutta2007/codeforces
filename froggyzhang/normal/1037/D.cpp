#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define N 200200
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
int n,q[N];
map<int,int> mp[N];
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		mp[u][v]=mp[v][u]=1;
	}
	for(int i=1;i<=n;++i)q[i]=read();
	int pos=2;
	for(int i=1;i<=n;i++){
		while(mp[q[i]][q[pos]])++pos;
	}
	if(q[1]^1||pos<=n){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}