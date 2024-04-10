#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1002],ans,v[1002];
int main(){
	t=read();
	while(t--){
		n=read()*2;memset(v,0,sizeof(v));
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=1;i<=n;++i){
			if(!v[a[i]]){
				printf("%d ",a[i]);
				v[a[i]]=1;
			}
		}
		puts("");
	}
}