#include<stdio.h>
int en[300100];
int ee[300100][3];
int loc[300100];
int q[5001000];
int qs,qe;
int n,m;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&j,&k);
		ee[j][en[j]]=k;
		en[j]++;
		ee[k][en[k]]=j;
		en[k]++;
	}
	for(i=1;i<=n;i++){
		q[i-1]=i;
	}
	qe=n;
	for(qs=0;qs<qe;qs++){
		i=q[qs];
		k=0;
		for(j=0;j<en[i];j++){
			k+=1^loc[i]^loc[ee[i][j]];
		}
		if(k<2)continue;
		loc[i]=1-loc[i];
		for(j=0;j<en[i];j++){
			q[qe]=ee[i][j];
			qe++;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d",loc[i]);
	}
}