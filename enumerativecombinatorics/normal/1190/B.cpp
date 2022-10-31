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
int p[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	std::sort(p,p+a);
	long long sum=0;
	set<int>S;
	for(int i=0;i<a;i++)S.insert(p[i]);
	for(int i=0;i<a;i++)sum+=p[i];
	if(a==1||sum==0){
		if(sum%2==0)printf("cslnb\n");
		else printf("sjfnb\n");
		return 0;
	}
	bool dame=false;
	int cnt=0;
	for(int i=0;i<a-1;i++){
		if(p[i]==p[i+1]){
			cnt++;
			if(p[i]==0||S.count(p[i]-1))dame=true;
		}
	}
	if(cnt>1)dame=true;
	if(dame){
		printf("cslnb\n");return 0;
	}
	long long val=0;
	for(int i=0;i<a;i++){
		val+=p[i]-i;
	}
	if(val%2==0)printf("cslnb\n");
	else printf("sjfnb\n");
}