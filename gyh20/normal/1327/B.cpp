#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[100002],c[100002],k,x,lst;
signed main(){
	t=read();
	while(t--){
		n=read();for(re int i=1;i<=n;++i)c[i]=0;lst=0;
		for(re int i=1;i<=n;++i){
			k=read();bool pp=0;
			for(re int j=1;j<=k;++j){
				re int x=read();
				if(!pp&&!c[x]){
					pp=c[x]=1;
				}
			}
			if(!pp)lst=i;
		}
		if(lst){
			for(re int i=1;i<=n;++i){
				if(!c[i]){
				printf("IMPROVE\n%d ",lst);printf("%d\n",i);break;}
			}
		}
		else{
			puts("OPTIMAL");
		}
	}
}