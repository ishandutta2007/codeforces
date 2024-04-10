//if this gets AC i will shoot myself
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, m;
unsigned arr[100004];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	unsigned type,l,r,xr;
    long long sum;
	for(int t=0;t<m;t++){
		scanf("%d",&type);
		if(type==1){
			sum=0;
			scanf("%d %d",&l,&r);
            for(int i=l;i<=r;i++) sum+=arr[i];
			printf("%I64d\n",sum);
		} else {
			scanf("%d %d %d",&l,&r,&xr);
			for(int i=l;i<=r;i++){
				arr[i]^=xr;
			}
		}
	}
}