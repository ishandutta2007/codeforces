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
int T,n,k,s[N],a[N];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		a[0]=a[n+1]=1e9+1;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			s[i]=s[i-1];
			if(a[i]>a[i-1]&&a[i]>a[i+1])++s[i];
		}
		int pos=0,ans=0;
		for(int i=k;i<=n;++i){
			if(ans<s[i-1]-s[i-k+1]+1)pos=i-k+1,ans=s[i-1]-s[i-k+1]+1;
		}
		printf("%d %d\n",ans,pos);
	}
	return 0;
}