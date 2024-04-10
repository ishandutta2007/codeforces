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
long long p[210000];
int x[210000];
int t[210000];
long long ret[210000];
int main(){
	int a;scanf("%d",&a);
	long long b;scanf("%I64d",&b);
	for(int i=0;i<a;i++){
		scanf("%I64d",p+i);
	}
	for(int i=0;i<a;i++){
		scanf("%d",x+i);
	}
	int now=0;
	int las=0;
	for(int i=0;i<a;i++){
		if(x[i]<=i||las>x[i]||(now>i&&now<x[i])){
			printf("No\n");return 0;
		}
		if(now<x[i]){
			now++;
			while(now<x[i]){
				t[now]=1;
				now++;
			}
			t[now]=-1;
		}
		las=x[i];
	}
	for(int i=0;i<a-1;i++){
		if(t[i+1]==1){
			ret[i]=p[i+1]+b;
		}else{
			ret[i]=p[i+1]+b-1;
		}
	}
	ret[a-1]=3000000000000000000LL;
	for(int i=0;i<a-1;i++){
		if(ret[i]==ret[i+1]){
			printf("No\n");return 0;
		}
	}
	printf("Yes\n");
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%I64d",ret[i]);
	}printf("\n");
}