#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a[4]={0,2,3,1}; 
inline ll c2(ll n,ll d){
	if(n==1)return 1;
	ll m=n/4;
	for(int i=0;i<=3;++i)
	    if((i+1)*m>=d)return c2(m,d-i*m)+a[i]*m;
} 
inline ll calc2(ll n){
	ll num=2,t=1;
	while(n>0){
		if(n-t<=0)break;
	    n-=t;t*=4;num<<=2; 
	}
	return num-1+c2(t,n);
}
inline ll calc1(ll n){
	ll num=1,t=1;
	while(n>0){
		if(n-t<=0)break;
		n-=t;num<<=2;t*=4;
	}
	return num-1+n;
}

int main(){
	int t;
	scanf("%d",&t);
	ll n;
	while(t--){
		scanf("%lld",&n);
		ll P=(n+2)/3;
		if(n%3==1)printf("%lld\n",calc1(P));
		else if(n%3==2)printf("%lld\n",calc2(P));
		else{
			ll res1=calc1(P);
			ll res2=calc2(P);
			printf("%lld\n",res1^res2);
		}
	} 
	return 0;
}