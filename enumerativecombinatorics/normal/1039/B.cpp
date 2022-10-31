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
const long double EPS=1e-13;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
char in[110];
int main(){
	srand(time(NULL));
	long long n;
	int b;
	scanf("%I64d%d",&n,&b);
	long long L=1;
	long long R=n;
	int ss=0;
	while(1){
		if(R-L+1<=65){
		    ss++;
			long long at=L+(rand()+ss)%(R-L+1);
			printf("%I64d %I64d\n",at,at);
			fflush(stdout);
			scanf("%s",in);
			if(in[0]=='Y')return 0;
			else{
				L=max(L-10,1LL);
				R=min(n,R+10);
			}
		}else{
			long long M=(L+R)/2;
			printf("%I64d %I64d\n",L,M);
			fflush(stdout);
			scanf("%s",in);
			if(in[0]=='Y'){
				L=max(1LL,L-10);
				R=min(n,M+10);
			}else{
				L=max(1LL,M+1-10);
				R=min(n,R+10);
			}
		}
	}
}