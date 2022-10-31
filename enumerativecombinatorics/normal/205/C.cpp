#include<stdio.h>
#include<algorithm>
using namespace std;
long long calc(long long a){
	if(a<10LL)return a;
	if(a==10LL)return 9;
	long long t=1;
	long long ret=0;
	while(t<a){
		if(t==10)ret+=t/10*9;
		else ret+=t/100*9;
		t*=10;
	}
	t/=10;
	//printf("%lld %lld\n",ret,t);
	for(int i=1;i<=9;i++){
		if(t*i>a)break;
		if(t*(i+1)<a){
			if(t==1)ret++;
			else ret+=t/10;
		}else{
			if(a-i-t*i>=0LL)ret+=(a-i-t*i)/10+1;
		}
	}
	return ret;
}
int main(){
	long long a,b;
	scanf("%I64d%I64d",&a,&b);
	printf("%I64d\n",calc(b)-calc(a-1));
}