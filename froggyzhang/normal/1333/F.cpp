#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 500050
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
int n,ntp[N],p[N],pn,f[N];
void init(int n){
	f[1]=ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=f[i]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=1;
			f[p[j]*i]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	n=read();
	init(n);
	for(int i=1;i<=n;++i){
		f[i]=i/f[i];
	}
	sort(f+1,f+n+1);
	for(int i=2;i<=n;++i){
		printf("%d ",f[i]);
	}
	return 0;
}