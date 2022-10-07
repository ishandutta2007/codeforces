#include<stdio.h>
int n,m;
double p[5010];
int d[5010];
double expv[5010];
double nexpv[5010];
double prob;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lf%d",&p[i],&d[i]);
		p[i]/=100;
	}
	for(i=n-1;i>=0;i--){
		nexpv[0]=0;
		prob=1;
		for(j=0;j<d[i];j++){
			prob*=1-p[i];
		}
		for(j=1;j<=m;j++){
			nexpv[j]=(nexpv[j-1]*(1-p[i]))+((expv[j-1]+1)*p[i]);
			if(j==d[i]){
				nexpv[j]+=prob;
			}
			else if(j>d[i]){
				nexpv[j]+=prob*(expv[j-d[i]]-expv[j-d[i]-1]);
			}
		}
		for(j=0;j<=m;j++){
			expv[j]=nexpv[j];
		}
	}
	printf("%.20lf",expv[m]);
}