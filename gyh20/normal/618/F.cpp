#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,lst[1000002],p[1000002],o;
long long a[1000002],b[1000002];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=a[i-1]+read();
	for(re int i=1;i<=n;++i)b[i]=b[i-1]+read();
	if(a[n]>b[n])swap(a,b),o=1;
	re int pos=0;
	for(re int i=0;i<=n;++i){
		while(pos<n&&b[pos+1]<=a[i])++pos;
		p[i]=pos;
		re int x=a[i]-b[pos];
		if(lst[x]||(i&&(x==0))){
			if(o==0){
				printf("%d\n",i-lst[x]);
				for(re int j=lst[x]+1;j<=i;++j)printf("%d ",j);puts("");
			}
			printf("%d\n",pos-p[lst[x]]);
			for(re int j=p[lst[x]]+1;j<=pos;++j)printf("%d ",j);
			if(o==1){
				printf("%d\n",i-lst[x]);
				for(re int j=lst[x]+1;j<=i;++j)printf("%d ",j);puts("");
			}return 0;
		}
		lst[x]=i;
	}
}