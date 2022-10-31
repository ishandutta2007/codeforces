#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
double dp[1<<20];
double p[22];
double q[22];
double ret[22];
int ind[22];
double EPS=1e-9;
int main(){
	int n,b;scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++){
		scanf("%lf",q+i);
	}
	int a=0;
	for(int i=0;i<n;i++){
		if(q[i]>EPS){
			p[a++]=q[i];
			ind[a-1]=i;
		}
	}
	b=min(b,a);
	dp[0]=1;
	for(int i=0;i<(1<<a)-1;i++){
		double tot=1;
		for(int j=0;j<a;j++){
			if(i&(1<<j))tot-=p[j];
		}
		if(tot<EPS)continue;
		for(int j=0;j<a;j++){
			if(i&(1<<j))continue;
			dp[i+(1<<j)]+=dp[i]*p[j]/tot;
		}
	}
	for(int i=0;i<(1<<a);i++){
		if(__builtin_popcount(i)!=b)continue;
		for(int j=0;j<a;j++)if(i&(1<<j))ret[ind[j]]+=dp[i];
	}
	for(int j=0;j<n;j++){
		if(j)printf(" ");
		printf("%.12f",ret[j]);
	}
	printf("\n");
}