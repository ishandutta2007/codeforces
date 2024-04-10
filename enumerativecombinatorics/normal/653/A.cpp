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
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[110];
int t[11000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
		for(int i=0;i<a;i++)t[p[i]]=1;
	for(int i=0;i<1100;i++){
		if(t[i]&&t[i+1]&&t[i+2]){
			printf("YES\n");return 0;
		}
	}printf("NO\n");
}