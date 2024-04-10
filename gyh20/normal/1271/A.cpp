#include<cstdio>
#include<iostream>
using namespace std;
long long a,b,c,d,e,f,ans;
int main(){
scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
if(e>f){
	if(a<d)ans+=a*e,d-=a;
	else ans+=d*e,d=0;
	if(d)ans+=min(d,min(b,c))*f;
}
else{
	if(min(b,c)<d)ans+=min(b,c)*f,d-=min(b,c);
	else ans+=d*f,d=0;
	if(d)ans+=min(a,d)*e;
}
printf("%lld",ans);
}