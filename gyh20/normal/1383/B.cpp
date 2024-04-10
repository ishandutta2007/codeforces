#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,ans,a[100002];
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		re bool ia=1;
		for(re int j=30;~j&&ia;--j){
			re int s=0;
			for(re int i=1;i<=n;++i)s+=(a[i]>>j)&1;
			if(s%2==0)continue;
			ia=0;
			re int x=s,y=n-x;
			if(y%2==0){
				if((s+1>>1)&1)puts("WIN");
				else puts("LOSE");
			}
			else puts("WIN");
		}
		if(ia)puts("DRAW");
	}
}