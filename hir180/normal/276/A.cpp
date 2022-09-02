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
	long long ans=-10000000000;
	int n;
	long long k;
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++){
		long long d,f;
		scanf("%lld %lld",&d,&f);
		if(f>k){
			ans=max(ans,d+k-f);
		}else{
			ans=max(ans,d);
		}
	}
	printf("%lld\n",ans);
	return 0;
}