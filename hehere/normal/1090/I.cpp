#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const ULL MD=1ll<<32ll;
int n[10005],A[10000005];
LL L[10005],R[10005],X[10005],Y[10005],Z[10005],B1[10005],B2[10005];
void solve(int n,LL L,LL R,ULL X,ULL Y,ULL Z,ULL B1,ULL B2,int T){
	int i,j,k;
	ULL B3;
	for(i=0;i<n;++i){
		if(i>=2){
			B3=(B1*X%MD+B2*Y%MD+Z)%MD;
			B1=B2;
			B2=B3;
		}
		A[i]=(((LL)(i==0?B1:B2))%(R-L+1ll))+L;
	}
	int mx=-5-(int)2e9,mn=(int)2e9+5;
	LL res=(LL)5e18;
	for(i=n-1;i>=0;--i){
		if(A[i]<=0){
			if(mx>A[i]) res=min(res,(LL)A[i]*(LL)mx);
		}
		mx=max(mx,A[i]);
	}
	for(i=0;i<n;++i){
		if(A[i]>=0){
			if(mn<A[i]) res=min(res,(LL)A[i]*(LL)mn);
		}
		mn=min(mn,A[i]);
	}
	if(res>(LL)4.5e18)
		printf("IMPOSSIBLE\n");
	else
		printf("%I64d\n",res);
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;++i){
		scanf("%d",n+i);
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",L+i,R+i,X+i,Y+i,Z+i,B1+i,B2+i);
	}
	for(i=0;i<t;++i){
		solve(n[i],L[i],R[i],X[i],Y[i],Z[i],B1[i],B2[i],i);
	}
	return 0;
}