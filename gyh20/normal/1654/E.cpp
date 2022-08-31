#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[100002],B,ans,b[100002],c[200002];
inline int calc(){
	re int s=0;
	for(re int i=0;i<=B;++i){
		for(re int j=1;j<=n;++j)b[j]=a[j]-j*i;
		sort(b+1,b+n+1);
		for(re int j=1;j<=n;++j){
			re int o=j;
			while(b[j]==b[j+1]&&j<n)++j;
			s=max(s,j-o+1);
		}
	}
	return n-s;
}
int main(){
	n=read(),B=300,ans=n;
	for(re int i=1;i<=n;++i)a[i]=read();
	ans=calc(),reverse(a+1,a+n+1),ans=min(ans,calc());
	for(re int i=1;i<=n;++i){
		re int nn=min(400,n-i+1);
		for(re int j=1;j<=nn;++j)b[j]=a[j+i-1];
		for(re int j=nn;j;--j)b[j]-=b[1];
		re int s=0;
		for(re int j=2;j<=nn;++j)
			if(b[j]%(j-1)==0)
				s=max(s,++c[b[j]/(j-1)+100000]);
		for(re int j=2;j<=nn;++j)
			if(b[j]%(j-1)==0)
				--c[b[j]/(j-1)+100000];
		ans=min(ans,n-s-1);
	}
	printf("%d",ans);
}