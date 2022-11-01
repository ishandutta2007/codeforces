#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int T,n,a[N],buc[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=0;i<n;++i)buc[i]=0;
		for(int i=1;i<=n;++i){
			a[i]=read()+i;
			a[i]=(a[i]%n+n)%n;
			++buc[a[i]];
		}
		bool ok=true;
		for(int i=0;i<n;++i){
			if(buc[i]^1){
				ok=false;
				break;
			}
		}
		if(ok){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}