#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	long long n,k;
	cin >> n >> k;
	if(n==1){
		puts("0");
		return 0;
	}
	int ans=1;
	long long lb=-2;
	long long ub=k+2;
	while(ub-lb>1){
		long long mid=(lb+ub)/2;
		if((k+mid)*(k-mid+1)/2>n+(k-mid+1)){
			lb=mid;
		}else{
			ub=mid;
		}
	}
	for(long long int i=ub+5;i>=lb-5;i--){
		if(i>=2 && i<=k){
			long long aw=k-i+1;
			long long sum=(k+i)*(k-i+1)/2;
			sum-=(aw-1);
			if(sum>=n){
				printf("%lld\n",k-i+1);
				return 0;
			}
		}
	}
	puts("-1");
}