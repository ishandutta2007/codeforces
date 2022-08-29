#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[100002],t;
int main(){
		n=read(),m=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=2;i<n;++i){
			if(a[i]>a[i-1]&&a[i]>a[i+1])++m;
			if(a[i]<a[i-1]&&a[i]<a[i+1])++m;
		}
		printf("%d\n",m);
	
}