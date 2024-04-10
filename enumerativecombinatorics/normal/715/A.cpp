#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
long long pv[110000];
long long ret[110000];
int main(){
	int a;scanf("%d",&a);
	pv[0]=2;
	for(int i=1;i<a;i++){
		pv[i]=(long long)i*(i+1);
	}
	for(int i=0;i<a;i++){
		long long t=(long long)(i+1)*(i+2);
		long long s=t*(i+2);
		ret[i]=s-pv[i]/(i+1);
	}
	for(int i=0;i<a;i++)printf("%I64d\n",ret[i]);
}