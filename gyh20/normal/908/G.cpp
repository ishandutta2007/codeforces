#include<cstdio>
#include<cstring>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
char s[702];
int n,f[702][702][2],ans,nw;
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline void calc(re int x){
	memset(f,0,sizeof(f));
	f[0][0][1]=1;
	for(re int i=0;i<n;++i)
		for(re int j=0;j<=i;++j)
			for(re int k=0;k<2;++k)
				if(f[i][j][k]){
					for(re int l=0;l<=(k?s[i+1]-'0':9);++l)add(f[i+1][j+(l>=x)][k&(l==s[i+1]-'0')],f[i][j][k]);
				}
	nw=0;
	for(re int i=0;i<=n;++i)add(ans,(1ll*nw*(f[n][i][0]+f[n][i][1]))%M),nw=10ll*nw%M+1;
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(re int i=1;i<=9;++i)calc(i);
	printf("%d",ans);
}