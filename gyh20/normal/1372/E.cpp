#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[102][102],L[102][102],R[102][102],len[102],s[102];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i){
		len[i]=read();
		for(re int j=1;j<=len[i];++j)L[i][j]=read(),R[i][j]=read();
	}
	for(re int Len=1;Len<=m;++Len)
		for(re int l=1;l+Len-1<=m;++l){
			re int r=l+Len-1;
			memset(s,0,sizeof(s));
			for(re int i=1;i<=n;++i)
				for(re int j=1;j<=len[i];++j)
					if(L[i][j]>=l&&R[i][j]<=r)
						for(re int k=L[i][j];k<=R[i][j];++k)
							++s[k];
			for(re int i=l;i<=r;++i)f[l][r]=max(f[l][r],f[l][i-1]+f[i+1][r]+s[i]*s[i]);
		}
	printf("%d",f[1][m]);
}