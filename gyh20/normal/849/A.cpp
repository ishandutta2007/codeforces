#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int a[102],n,f[2][102];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	f[0][0]=1;
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=i;++j)
			if((i-j)%2==0&&a[i]%2==1&&a[j]%2==1)
				f[1][i]|=f[0][j-1],f[0][i]|=f[1][j-1];
	}
	puts(f[1][n]?"Yes":"No");
}