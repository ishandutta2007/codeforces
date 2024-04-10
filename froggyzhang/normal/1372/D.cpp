#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
typedef long long ll;
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
int n,a[N];
ll pre[N][2],suf[N][2],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		pre[i][1]=a[i]+pre[i-1][0];
		pre[i][0]=pre[i-1][1];
	}
	for(int i=n;i>=1;--i){
		suf[i][1]=a[i]+suf[i+1][0];
		suf[i][0]=suf[i+1][1];
	}
	for(int i=0;i<=n;++i){
		ans=max(ans,pre[i][1]+suf[i+1][1]);
	}
	printf("%I64d\n",ans);
	return 0;
}