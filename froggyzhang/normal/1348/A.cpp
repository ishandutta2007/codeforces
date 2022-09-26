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
int T,n;
int main(){
	T=read();
	while(T--){
		n=read();
		int ans=(1<<n);
		for(int i=1;i<n/2;++i){
			ans+=1<<i;
		}
		for(int i=n/2;i<n;++i){
			ans-=1<<i;
		}
		printf("%d\n",ans);
	}
	return 0;
}