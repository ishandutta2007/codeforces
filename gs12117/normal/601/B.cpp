#include<stdio.h>
int n,q;
int a[100100];
int b[100100];
int qry[110][2];
int stk[100100];
long long int ans;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<q;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
	}
	for(i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]<0)b[i]=-b[i];
	}
	for(i=0;i<q;i++){
		qry[i][0]--;
		qry[i][1]--;
		ans=0;
		stk[0]=qry[i][0]-1;
		k=1;
		for(j=qry[i][0];j<qry[i][1];j++){
			while(k>1&&b[stk[k-1]]<b[j]){
				ans+=((long long int)(j-stk[k-1]))*(stk[k-1]-stk[k-2])*b[stk[k-1]];
				k--;
			}
			stk[k]=j;
			k++;
		}
		while(k>1){
				ans+=((long long int)(qry[i][1]-stk[k-1]))*(stk[k-1]-stk[k-2])*b[stk[k-1]];
			k--;
		}
		printf("%I64d\n",ans);
	}
}