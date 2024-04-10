#include<cstdio> 
#include<algorithm>
using namespace std;
typedef long long LL;
LL read(){LL x;scanf("%lld",&x);return x;}
int main(){
	LL l=read(),r=read(),a=read(),ans;
	if(r>=l)
		if(r>=l+a)ans=l+a;
		else ans=(r+l+a)/2;
	else
		if(l>=r+a)ans=r+a;
		else ans=(r+l+a)/2;
	printf("%lld",ans*2);
}