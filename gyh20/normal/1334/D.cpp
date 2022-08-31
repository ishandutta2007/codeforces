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
int t,n,l,r;
inline void work(re int x,re int y,re int z,re int len){
	if(len==0)return;
	if(x==n){
		printf("1 ");
		return;
	}
	printf("%lld ",z);
	if(z==x){
		work(x,y,y,len-1);
		return;
	}
	if(z==y){
		if(y!=n){
			work(x,y+1,x,len-1);
		}
		else work(x+1,x+2,x+1,len-1);
	}
}
signed main(){
	t=read();
	while(t--){
		n=read();l=read()-1;r=read()-1;re int sum=0,ans=0,tot;
		for(re int i=n;i;--i){
			if(i!=1)
			sum+=2*i-2;
			else sum+=1;
			if(sum>l){
			//	printf("%lld %lld\n",i,sum);
			if(i!=1)
				sum-=2*i-2;else ++sum;
				ans=n-i+1;
				break;
			}
		}tot=ans+1;
		for(re int i=2;i<=l-sum;i+=2)++tot;
		if((l-sum)&1){work(ans,tot,tot,r-l+1);}
		else work(ans,tot,ans,r-l+1);putchar('\n');
	}
}