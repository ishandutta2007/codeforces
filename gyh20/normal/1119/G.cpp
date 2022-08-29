#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],sum[1000002],b[1000002],S,pos;
int main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i)a[i]=read(),sum[i]=(sum[i-1]+a[i])%n,S+=a[i];
	sum[m]=n;
	sort(sum+1,sum+m+1);
	printf("%d\n",(S+n-1)/n);
	for(re int i=1;i<=m;++i)printf("%d ",b[i]=sum[i]-sum[i-1]);
	puts(""),pos=1;
	for(re int i=1;i<=(S+n-1)/n;++i){
		for(re int j=1;j<=m;++j){
			while(pos<m&&!a[pos])++pos;
			a[pos]-=b[j],printf("%d ",pos);
		}puts("");
	}
}