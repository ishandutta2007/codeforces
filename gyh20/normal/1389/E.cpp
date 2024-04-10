#include<bits/stdc++.h>
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
} 
using namespace std;
int n,m,a,b,c,d,t,ans,lim;
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	t=read();
	while(t--){
		a=read(),b=read(),c=read();ans=0;
		lim=min(a,b)-1;c/=gcd(c,b-1);
		d=lim-lim%c-1;ans+=(lim-d)*(lim/c);
		ans+=(1+d/c)*(d/c)/2*c;
		printf("%lld\n",ans);
	}
}