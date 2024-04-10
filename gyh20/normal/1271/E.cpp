#include<cstdio>
#include<iostream>
#define re register
using namespace std;
unsigned long long n,k,ans,ans1;
int main(){
 scanf("%llu%llu",&n,&k);
 unsigned long long l=1,r=n/2;
 while(l<=r){
 	unsigned long long mid=((l+r)>>1),tmp,ll,q=0;
 	tmp=2;
 	ll=mid*2;
 	while(ll+tmp<=n){
 		ll<<=1;
 		q+=tmp;
 		tmp<<=1;
	 }
	 if(n>=ll)
	 q+=n-ll+1;
	 if(q>=k)l=mid+1,ans=mid*2;
	 else r=mid-1;
 }
 l=1;
 r=(n+1)/2;
  while(l<=r){
 	unsigned long long mid=((l+r)>>1),tmp,ll,q=0;
 	tmp=1;
 	ll=mid*2-1;
 	while(ll+tmp<=n){
 		ll<<=1;
 		q+=tmp;
 		tmp<<=1;
	 }
	 if(n>=ll)
	 q+=n-ll+1;
	 if(q>=k)l=mid+1,ans1=mid*2-1;
	 else r=mid-1;
 }
 if(ans>ans1)printf("%llu",ans);
 else printf("%llu",ans1);
}