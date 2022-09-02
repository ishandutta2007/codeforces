#include <stdio.h>
#include <string.h>
typedef long long ll;
ll n,m,k,x,y,t,ret; char a[1000005],b[1000005];
ll gcd(ll x,ll y){
	if(x<y){
		t=x;
		x=y;
		y=t;
	}
	if(x%y==0) return y;
	return gcd(y,x%y);
}
int main(){
	scanf("%lld%lld",&n,&m);
	scanf("%s%s",&a,&b);
	x=strlen(a); y=strlen(b);
	k=gcd(x,y);
	for(int i=0;i<k;i++){
		int cnta[26]={},cntb[26]={}; ll rem=0;
		for(int j=i;j<x;j+=k) cnta[a[j]-'a']++;
		for(int j=i;j<y;j+=k) cntb[b[j]-'a']++;
		for(int j=0;j<26;j++) rem+=1LL*cnta[j]*cntb[j];
		ret+=1LL*(x/k)*(y/k)-rem;
	}
	printf("%lld\n",ret*(n*k/y));
}