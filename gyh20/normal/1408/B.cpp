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
		n=read(),m=read();
		for(re int i=1;i<=n;++i)a[i]=read();a[0]=-1;
		if(m==1){
			if(a[1]==a[n])puts("1");
			else puts("-1");
			continue;
		}ans=0;
		for(re int i=1;i<=n;++i)if(a[i]^a[i-1])++ans;
		if(ans>m)
		printf("%d\n",(ans-m-1)/(m-1)+2);
		else puts("1");
	}
}