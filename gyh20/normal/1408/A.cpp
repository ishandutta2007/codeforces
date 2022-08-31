#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],b[1000002],t,ans,c[1000002],p[1000002];
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(); 
		for(re int i=1;i<=n;++i)b[i]=read(); 
		for(re int i=1;i<=n;++i)c[i]=read(),p[i]=0;
		for(re int i=1;i<n;++i)if(a[i]!=p[i-1])p[i]=a[i];else if(b[i]!=p[i-1])p[i]=b[i];else p[i]=c[i];
		if(a[n]!=p[1]&&a[n]!=p[n-1])p[n]=a[n];
		else if(b[n]!=p[1]&&b[n]!=p[n-1])p[n]=b[n];
		else p[n]=c[n];
		for(re int i=1;i<=n;++i)printf("%d ",p[i]);
		puts("");
	}
}