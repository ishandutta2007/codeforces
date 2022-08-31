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
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
int n,m,a,b;
inline int check(re int x){
	re int xx=a;
	while(xx%x==0){xx/=x;
	}
	return xx; 
}
signed main(){
	re int t=read();
	while(t--){
		a=read(),b=read();re int ans=0;
		if(a%b!=0)printf("%lld\n",a);
		else {
			re int x=sqrt(b);
			for(re int i=2;i<=x;++i){
				if(b%i==0){
					re int num=1,ss=a;
					while(b%i==0)b/=i,num*=i;
					ans=max(ans,check(i)*num/i);
				}
			}
			if(b^1)ans=max(ans,check(b));
			printf("%lld\n",ans);
		}
	}
}