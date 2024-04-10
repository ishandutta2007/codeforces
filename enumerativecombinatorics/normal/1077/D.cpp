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
int p[210000];
int t[210000];

int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
		t[p[i]]++;
	}
	int left=0;
	int right=210000;
	while(left+1<right){
		int M=(left+right)/2;
		long long tmp=0;
		for(int i=0;i<210000;i++){
			tmp+=t[i]/M;
		}
		if(tmp>=b){
			left=M;
		}else right=M;
	}
	int cnt=0;
	for(int i=0;i<210000;i++){
		int num=t[i]/left;
		for(int j=0;j<num;j++){
			if(cnt==b)break;
			if(cnt)printf(" ");
			printf("%d",i);
			cnt++;
		}
		if(cnt==b)break;
	}
	printf("\n");
}