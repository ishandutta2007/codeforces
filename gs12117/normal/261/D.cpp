#include<stdio.h>
int tcn,n,m,p,tc;
int a[100100];
int dp[100100];
int mdp[100100];
int alist[100100];
int aln;
int main(){
	int i,j,k,l;
	scanf("%d%d%d%d",&tcn,&n,&m,&p);
	if(p>=m)p=m;
	for(tc=0;tc<tcn;tc++){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		k=0;
		for(i=0;i<=m;i++){
			dp[i]=0;
			mdp[i]=0;
		}
		for(i=0;i<m;i++){
			aln=0;
			for(j=0;j<n;j++){
				if(a[j]==i){
					alist[aln]=j;
					aln++;
				}
			}
			if(aln==0)continue;
			for(j=0;j<=k;j++){
				dp[j+1]=999999999;
				for(l=0;l<aln;l++){
					if(dp[j+1]>(mdp[j]-alist[l]+n-1)/n*n+alist[l]){
						dp[j+1]=(mdp[j]-alist[l]+n-1)/n*n+alist[l];
					}
				}
			}
			k++;
			mdp[k]=999999999;
			for(j=0;j<=k;j++){
				if(dp[j]<mdp[j])mdp[j]=dp[j];
			}
		}
		for(i=0;i<=k;i++){
			if(mdp[i]>=p*n)break;
		}
		i--;
		printf("%d\n",i);
	}
	return 0;
}