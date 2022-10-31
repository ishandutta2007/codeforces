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
const long long mod=924844033;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}

int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);
		long long ret=0;
		ret+=(long long)(p-q)*(r/2);
		if(r%2)ret+=p;
		printf("%I64d\n",ret);
	}
}