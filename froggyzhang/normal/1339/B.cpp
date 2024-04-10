#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int T,n,a[N],b[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		int l=1,r=n;
		for(int i=1;i<=n;++i){
			if(i&1)b[i]=a[r--];
			else b[i]=a[l++];
		}
		reverse(b+1,b+n+1);
		for(int i=1;i<=n;++i){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	getchar(),getchar();
	return 0;
}