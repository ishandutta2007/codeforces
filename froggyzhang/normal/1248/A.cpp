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
int T,n,m,p[2],q[2];
int main(){
	T=read();
	while(T--){
		n=read();p[0]=p[1]=q[0]=q[1]=0;
		for(int i=1;i<=n;i++){
			int x=read();
			p[x%2]++;
		}
		m=read();
		for(int i=1;i<=m;i++){
			int x=read();
			q[x%2]++;
		}
		printf("%I64d\n",1LL*p[0]*q[0]+1LL*p[1]*q[1]);
	}
	return 0;
}