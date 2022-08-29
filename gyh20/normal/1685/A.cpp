#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,a[1000002],A,B,ans,b[1000002];
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		if(n&1){
			puts("NO");
			continue;
		}
		sort(a+1,a+n+1);re bool ia=0;
		for(re int i=(n>>1)+1;i<n;++i)ia|=(a[i]==a[i-(n>>1)+1]);
		ia|=a[n]==a[(n>>1)];
		if(ia){
			puts("NO");
			continue;
		}
		re int pos=1;
		for(re int i=1;i<=n;++i){
			b[pos]=a[i];
			pos+=2;
			if(pos>n)pos-=n,++pos;
		}
		puts("YES");
		for(re int i=1;i<=n;++i)printf("%d ",b[i]);puts("");
	}
}