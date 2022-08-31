#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[502][502],S[502][502],ans,ia;
char s[502][502];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(re int i=n;~i;--i)
		for(re int j=m;~j;--j)
			s[i][j]=s[i][j]=='B',a[i][j]=s[i][j]^s[i+1][j]^s[i][j+1]^s[i+1][j+1]; 
	for(re int i=1;i<=n;++i)for(re int j=1;j<=m;++j)ans+=a[i][j];
	for(re int i=1;i<n;++i)for(re int j=1;j<m;++j)if(a[i][j]&&a[i][m]&&a[n][j]&&a[n][m])ia=1;
	printf("%d",ans-ia);
}