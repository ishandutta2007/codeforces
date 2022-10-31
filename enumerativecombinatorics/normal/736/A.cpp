#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;

int main(){
	long long a;scanf("%I64d",&a);
	int ret=0;
	long long t1=1;
	long long t2=1;
	while(t1<=a){
		if(t1<=a)ret++;
		long long t3=t1+t2;
		t2=t1;
		t1=t3;
	}
	printf("%d\n",ret-1);
}