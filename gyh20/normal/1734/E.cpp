#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[502],f[502][502];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		for(re int j=0;j<n;++j)f[i][j]=(f[i-1][j]+j)%n;
		while(f[i][i-1]!=a[i]){
			for(re int j=0;j<n;++j)f[i][j]=(f[i][j]+1)%n;
		}
		for(re int j=0;j<n;++j)printf("%d ",f[i][j]);
		puts("");
	}
}