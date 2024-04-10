#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,C,D,T[100002],nxt[100002],f[100002][2];
char s[100002][3];
signed main(){
	n=read(),C=read(),D=read();
	for(re int i=1;i<=n;++i)T[i]=read(),scanf("%s",s[i]);
	T[n+1]=read();
	for(re int i=n;i;--i)if(s[i][0]^s[i+1][0])nxt[i]=i+1;else nxt[i]=nxt[i+1];
	for(re int i=1;i<=n;++i){
		f[i][0]=f[i-1][0]+D;
		f[i][1]=f[i-1][0]+(T[nxt[i]]-T[i])*C;
		if(s[i][0]!=s[i-1][0])f[i][1]=min(f[i][1],f[i-1][1]+(T[nxt[i]]-T[i])*C);
		else f[i][1]=min(f[i][1],f[i-1][1]+min(D,(T[nxt[i]]-T[i])*C));
	}
	printf("%lld",min(f[n][0],f[n][1]));
}