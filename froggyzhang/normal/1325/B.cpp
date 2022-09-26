#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int T,a[N],n;
int main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i==1||a[i]^a[i-1])++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}