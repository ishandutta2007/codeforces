#include<stdio.h>
#define BSIZ 300
int n,q;
int a[340][310];
int an[340];
int ap[340];
long long int clf[340][300];
long long int clfs[340];
long long int clfp[340];
int qry[100100][4];
void spl(int bkn){
	int i;
	if(an[bkn]==0)return;
	an[bkn]=0;
	for(i=0;i<BSIZ;i++){
		clf[bkn][i]+=clfp[bkn];
		a[bkn][i]=ap[bkn];
	}
	clfp[bkn]=0;
}
void ccol(int bkn,int x,int y,int cl){
	spl(bkn);
	int i;
	for(i=x;i<=y;i++){
		if(a[bkn][i]>cl){
			clf[bkn][i]+=a[bkn][i]-cl;
			clfs[bkn]+=a[bkn][i]-cl;
		}
		else{
			clf[bkn][i]-=a[bkn][i]-cl;
			clfs[bkn]-=a[bkn][i]-cl;
		}
		a[bkn][i]=cl;
	}
}
void mcol(int x,int y,int cl){
	int i,j;
	for(i=x;i<=y;i++){
		if(an[i]==0){
			an[i]=1;
			for(j=0;j<BSIZ;j++){
				if(a[i][j]>cl){
					clf[i][j]+=a[i][j]-cl;
					clfs[i]+=a[i][j]-cl;
				}
				else{
					clf[i][j]-=a[i][j]-cl;
					clfs[i]-=a[i][j]-cl;
				}
			}
			clfp[i]=0;
		}
		else{
			if(cl>ap[i]){
				clfp[i]+=cl-ap[i];
				clfs[i]+=BSIZ*((long long int)cl-ap[i]);
			}
			else{
				clfp[i]-=cl-ap[i];
				clfs[i]-=BSIZ*((long long int)cl-ap[i]);
			}
		}
		ap[i]=cl;
	}
}
long long int csum(int bkn,int x,int y){
	spl(bkn);
	long long int res=0;
	int i;
	for(i=x;i<=y;i++){
		res+=clf[bkn][i];
	}
	return res;
}
long long int msum(int x,int y){
	long long int res=0;
	int i;
	for(i=x;i<=y;i++){
		res+=clfs[i];
	}
	return res;
}
int main(){
	int i;
	scanf("%d%d",&n,&q);
	for(i=0;i<=n;i++){
		a[i/BSIZ][i%BSIZ]=i;
	}
	for(i=0;i<q;i++){
		scanf("%d",&qry[i][0]);
		if(qry[i][0]==1){
			scanf("%d%d%d",&qry[i][1],&qry[i][2],&qry[i][3]);
			if(qry[i][1]/BSIZ==qry[i][2]/BSIZ){
				ccol(qry[i][1]/BSIZ,qry[i][1]%BSIZ,qry[i][2]%BSIZ,qry[i][3]);
			}
			else{
				ccol(qry[i][1]/BSIZ,qry[i][1]%BSIZ,BSIZ-1,qry[i][3]);
				mcol(qry[i][1]/BSIZ+1,qry[i][2]/BSIZ-1,qry[i][3]);
				ccol(qry[i][2]/BSIZ,0,qry[i][2]%BSIZ,qry[i][3]);
			}
		}
		else{
			long long int res=0;
			scanf("%d%d",&qry[i][1],&qry[i][2]);
			if(qry[i][1]/BSIZ==qry[i][2]/BSIZ){
				res=csum(qry[i][1]/BSIZ,qry[i][1]%BSIZ,qry[i][2]%BSIZ);
			}
			else{
				res=csum(qry[i][1]/BSIZ,qry[i][1]%BSIZ,BSIZ-1);
				res+=msum(qry[i][1]/BSIZ+1,qry[i][2]/BSIZ-1);
				res+=csum(qry[i][2]/BSIZ,0,qry[i][2]%BSIZ);
			}
			printf("%I64d\n",res);
		}
	}
}