#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
} 
int n,t,l,r;
inline int work(re int x,re int y){
	if(y==0)return x;
	re int p=y/4;
	if(x<p)return work(x,y/4);
	else if(x<2*p)return work(x-p,y/4)+y/2;
	else if(x<3*p)return work(x-2*p,y/4)+3*y/4;
	else return work(x-3*p,y/4)+y/4;
}
signed main(){
	t=read();
	while(t--){
		re int m=read();
		n=(m-1)/3+1;
		re int b=1,siz=0;
		while(siz<n)siz+=b,b*=4;siz-=b/4;
		re int xx=n-siz-1;n=b/4+n-siz-1;
		re int ans=work(n-b/4,b/4)+b/2;
		if(m%3==1){
			printf("%lld\n",n);
			continue;
		}
		else if(m%3==2){
			printf("%lld\n",ans);
			continue;
		}
		else printf("%lld\n",ans^n);
	}
}