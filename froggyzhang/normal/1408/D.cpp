#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
const int mx=1000005;
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
int n,m,a[N],b[N],c[N],d[N],s[N],ans;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
	}
	for(int i=1;i<=m;++i){
		c[i]=read(),d[i]=read();
		for(int j=1;j<=n;++j){
			if(a[j]>c[i]||b[j]>d[i])continue;
			s[c[i]-a[j]]=max(s[c[i]-a[j]],d[i]-b[j]+1);
		}
	}
	ans=2e6+2333;
	for(int i=mx;i>=0;--i){
		s[i]=max(s[i],s[i+1]);
		ans=min(ans,i+s[i]);
	}
	printf("%d\n",ans);
	return 0;
}