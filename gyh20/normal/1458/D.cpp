#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],sum[500002];
char s[500002];
inline void Out(re int x){
	while(a[x-1]>1)putchar('0'),--a[x-1],Out(x-1);
	while(a[x]>1)putchar('1'),--a[x],Out(x+1);
	if(a[x-1])putchar('0'),--a[x-1],Out(x-1);
	if(a[x])putchar('1'),--a[x],Out(x+1);
}
int main(){
	int t=read();
	while(t--){
		scanf("%s",s+1),n=strlen(s+1);
		sum[0]=500000;
		for(re int i=1;i<=n;++i)sum[i]=sum[i-1]+(s[i]=='1'?1:-1);
		for(re int i=0;i<n;++i)++a[min(sum[i],sum[i+1])];
		Out(500000),puts("");
	}
}