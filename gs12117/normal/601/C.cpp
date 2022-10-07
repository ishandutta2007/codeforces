#include<stdio.h>
int n,m;
int x[110];
int pres;
double prob[110000];
double bprob[110000];
double ans;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
		x[i]--;
		pres+=x[i];
	}
	prob[0]=1;
	for(i=0;i<n;i++){
		bprob[0]=0;
		for(j=m;j<=(i+3)*m;j++){
			bprob[j+1]=prob[j-m]+bprob[j];
		}
		for(j=0;j<=(i+1)*(m-1);j++){
			prob[j]=bprob[j+m+1]-bprob[j+1]-bprob[j+m+1-x[i]]+bprob[j+m-x[i]];
		}
		for(j=0;j<=(i+1)*(m-1);j++){
			prob[j]/=m-1;
		}
	}
	for(i=0;i<pres;i++){
		ans+=prob[i];
	}
	ans*=m-1;
	ans+=1;
	printf("%.20lf",ans);
}