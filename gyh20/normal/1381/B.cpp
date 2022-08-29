#include<bits/stdc++.h>
#define re register
#define M 998244353
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[1000002],b[1000002],t,l,r,ans[1000002],cnt,c[1000002],siz[1000002],p[100002];
char s[100002];
signed main(){
	t=read();
	while(t--){
		n=read()<<1;
		for(re int i=1;i<=n;++i)a[i]=read(),siz[i]=1,p[i]=0;
		for(re int i=1;i<=n;++i){
			for(re int j=i-1;j;--j){
				if(a[i]<a[j]&&siz[j]){
					siz[i]=0;
					++siz[j];
					break;
				}
			}
		}p[0]=1;
		for(re int i=1;i<=n;++i){
			if(siz[i]){
				for(re int j=n;~j;--j)if(p[j])p[j+siz[i]]=1;
			}
		}
		puts(p[n>>1]?"YES":"NO");
	}
}