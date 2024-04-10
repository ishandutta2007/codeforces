#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[200002][5],m,k,v[202];
bitset<200002>b[5],ans;
char s[200002],t[200002];
signed main(){
	n=read(),m=read(),k=read(),scanf("%s%s",s+1,t+1),v['T']=1,v['C']=2,v['G']=3;
	for(re int i=1;i<=n;++i)s[i]=v[s[i]];
	for(re int i=1;i<=m;++i)t[i]=v[t[i]];
	for(re int i=1;i<=n;++i)++a[max(1,i-k)][s[i]],--a[min(n+1,i+k+1)][s[i]];
	for(re int i=1;i<=n;++i){
		ans[i]=1;
		for(re int j=0;j<4;++j){
			a[i][j]+=a[i-1][j];
			if(a[i][j])b[j][i]=1;
		}
	}
	for(re int i=1;i<=m;++i)ans&=(b[t[i]]>>(i-1));
	printf("%d",ans.count());
}