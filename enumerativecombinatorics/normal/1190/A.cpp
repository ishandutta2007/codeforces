#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long x[110000];
int main(){
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i=0;i<b;i++){
		scanf("%lld",x+i);x[i]--;
	}
	long long ret=0;
	for(int i=0;i<b;){
		ret++;
		long long ori=x[i]-i;
		int t=i;
		while(i<b&&(x[i]-t)/c==ori/c){
			i++;
		}
	}
	printf("%lld\n",ret);
}