#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[500002],bl[500002],k,sum[500002],*Sum=sum+1,st[500002],ed[500002];
char s[500002];
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i){
		if(s[i]!=s[i-1])++k,st[k]=i;
		bl[i]=k,++a[k],ed[k]=i;
	}
	Sum[1]=a[1];
	for(re int i=2;i<=k;++i)Sum[i]=Sum[i-2]+a[i];
	while(m--){
		re int l=read(),r=read();
		if(bl[l]==bl[r])printf("%d\n",r-l+1);
		else{
			if((bl[l]^bl[r])&1){
				re int x1=Sum[bl[r]-2]-Sum[bl[l]-1]+r-st[bl[r]]+1-(bl[r]-bl[l]>>1);
				re int x2=Sum[bl[r]-1]-Sum[bl[l]]+ed[bl[l]]-l+1-(bl[r]-bl[l]>>1);
				printf("%d\n",max(x1,x2));
			}
			else{
				re int x1=Sum[bl[r]-2]-Sum[bl[l]]+r-st[bl[r]]+1+ed[bl[l]]-l+1-(bl[r]-bl[l]>>1);
				re int x2=Sum[bl[r]-1]-Sum[bl[l]-1]-(bl[r]-bl[l]-2>>1);
				printf("%d\n",max(x1,x2));
			}
		}
	}
}