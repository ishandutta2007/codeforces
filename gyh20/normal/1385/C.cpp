#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[200002],ans;
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		re int x=n;
		while(x&&a[x]<=a[x-1])--x;
		while(x&&a[x]>=a[x-1])--x;
		if(x)--x;
		printf("%d\n",x);
	}
}