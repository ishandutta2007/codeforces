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
int T,n,a[N];
int main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i]=(read()==i?0:1);
			if(a[i]&&!a[i-1])++ans;
		}
		printf("%d\n",min(ans,2));
	}
	return 0;
}