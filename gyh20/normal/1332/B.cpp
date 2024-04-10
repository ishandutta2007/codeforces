#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[100002],p[12]={2,3,5,7,11,13,17,19,23,29,31},col[1002],mx,lst;
signed main(){
	t=read();
	while(t--){
		n=read();memset(col,0,sizeof(col));mx=0;
		lst=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=0;i<11;++i){
			for(re int j=1;j<=n;++j){
				if((!col[j])&&(a[j]%p[i]==0)){
					if(mx!=i+1)++lst;
					col[j]=lst;
					mx=i+1;
				}
			}
		}
		mx=lst;
		printf("%d\n",mx);
		for(re int i=1;i<=n;++i)printf("%d ",col[i]);
		putchar('\n');
	}
}