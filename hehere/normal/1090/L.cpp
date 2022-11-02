#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,a,b,ac,bc,k,res;
bool check(int cnt){
	//printf("check %d\n",cnt);
	if(!cnt) return 1;
	LL c1=(LL)min(cnt,a)*(LL)ac/(LL)cnt,c2=(LL)min(cnt,b)*(LL)bc/(LL)cnt,r1=(LL)min(cnt,a)*(LL)ac%(LL)cnt,r2=(LL)min(cnt,b)*(LL)bc%(LL)cnt;
	//printf("%lld %lld %lld %lld\n",c1,c2,r1,r2);
	if(c1+c2>=(LL)k) return 1;
	LL tar=(LL)k-c1-c2;
	if(tar>1ll) return 0;
	if(r1+r2>=(LL)cnt) return 1;
	return 0;
}
int main(){
	int i,j;
	scanf("%d%d%d%d%d",&t,&n,&a,&b,&k);
	ac=(n+1)/2;
	bc=n-ac;
	int low=0,high=t,mid;
	while(low<high){
		mid=(low+high+1)/2;
		if(check(mid))
			low=mid;
		else
			high=mid-1;
	}
	printf("%d\n",min(low,t));
	return 0;
}