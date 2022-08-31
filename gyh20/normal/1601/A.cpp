#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,a[200002],n,m,b[42],ans,v[200002];
int main(){
	t=read();
	while(t--){
		ans=0,n=read();
		memset(b,0,sizeof(b));
		for(re int i=0;i<=n;++i)v[i]=0;
		for(re int i=1;i<=n;++i){
			re int x=read();
			for(re int j=0;j<30;++j)
				if(x&(1<<j))++b[j];
		}
		for(re int i=0;i<30;++i)++v[b[i]];
		for(re int i=1;i<=n;++i){
			re int x=0;
			for(re int j=0;j<=n;j+=i)x+=v[j];
			if(x==30)printf("%d ",i);
		}
		puts("");
	}
}