#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 2010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 1000000007
#define inf 1000000000
#define eps 1e-8
using namespace std;
ll n,l,r,k,i,ans;
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&l,&r,&k);
	r=(r+n-l+1)%n;
	if(k<r){printf("-1");return 0;}
	if(2*r>=k){
		ans=min(k+n-r*2+1,n);
		if(ans>=k-r){printf("%I64d",ans);return 0;}
	}
	for(i=1;i<=k;i++){
		l=max((k-n*i-r-1)/(i+1),(k-n*i-r*2-1)/i)+1;
		ans=min(min((k-n*(i-1)-r*2+1)/(i+1),(k-n*i-r)/i),n);
		if(ans>=l){
			printf("%I64d",ans);return 0;
		}
		if(i*i>=k)break;
	}i=min(i,n);
	for(;i>=0;i--){
		l=k%(n+i)-r;
		if((l<=min(i,r))&&(l>=max(i+r-n-1,0ll))){
			if(n+i>=k)printf("%I64d",min(i+1,n));
			else printf("%I64d",i);
			return 0;
		}
	}
	printf("-1");
}