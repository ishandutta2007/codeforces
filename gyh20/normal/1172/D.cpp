#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1002],b[1002],A[100002],B[100002],C[100002],D[100002];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)b[i]=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		re int px=1,py=1;
		for(re int j=1;j<=n;++j){
			if(a[j]==i)px=j;
			if(b[j]==i)py=j;
		}
		if(px!=i||py!=i)A[++m]=i,B[m]=px,C[m]=py,D[m]=i;
		swap(a[i],a[px]),swap(b[i],b[py]);
	}
	printf("%d\n",m);
	for(re int i=1;i<=m;++i)printf("%d %d %d %d\n",A[i],B[i],C[i],D[i]);
}