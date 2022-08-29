#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,a[12],sum[12];
int main(){
	t=read();
	while(t--){
		n=read();re int ttt=0,ans=2e9;
		for(re int i=1;i<=7;++i)a[i]=read(),ttt+=a[i];
		for(re int i=1;i<=7;++i){
			re int kk=n,sum=0,cur=i;
			while(kk){
				kk-=a[cur],++sum;
				if(cur==7){
					if(kk>ttt)sum+=(kk/ttt-1)*7,kk%=ttt,kk+=ttt;
					cur=1;
				}
				else ++cur;
			}
			ans=min(ans,sum);
		}
		printf("%d\n",ans);
	}
}