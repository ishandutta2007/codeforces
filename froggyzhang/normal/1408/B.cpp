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
int T,n,k,a[N];
int Solve(){
	int cnt=0;
	a[0]=-1;
	for(int i=1;i<=n;++i){
		if(a[i]^a[i-1])++cnt;
	}
	if(cnt==1)return 1;
	if(k==1)return -1;
	return (cnt-2)/(k-1)+1;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf("%d\n",Solve());
	}
	return 0;
}