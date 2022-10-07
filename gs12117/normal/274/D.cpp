#include<stdio.h>
#include<algorithm>
int n,m;
int a[100100];
int nnod;
int neg;
int edge[200100][2];
int en[200100];
int ben[200100];
int elist[200100];
int q[200100];
int qs,qe;
struct snod{
	int loc,val;
	bool operator<(const snod&r)const{
		return val<r.val;
	}
};
snod sp[100100];
int main(){
	int i,j,k,l,bnod;
	scanf("%d%d",&n,&m);
	nnod=m;
	neg=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i*m+j]);
			sp[j].loc=j;
			sp[j].val=a[i*m+j];
		}
		std::sort(sp,sp+m);
		j=0;
		while(j<m&&sp[j].val==-1)j++;
		bnod=-1;
		while(j<m){
			for(k=j;k<m;k++){
				if(sp[j].val!=sp[k].val){
					break;
				}
			}
			if(bnod!=-1){
				for(l=j;l<k;l++){
					edge[neg][0]=bnod;
					edge[neg][1]=sp[l].loc;
					neg++;
				}
			}
			if(k!=m){
				for(l=j;l<k;l++){
					edge[neg][0]=sp[l].loc;
					edge[neg][1]=nnod;
					neg++;
				}
				bnod=nnod;
				nnod++;
			}
			j=k;
		}
	}
	for(i=0;i<neg;i++){
		en[edge[i][0]+2]++;
		ben[edge[i][1]]++;
	}
	for(i=0;i<nnod+3;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<neg;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		en[edge[i][0]+1]++;
	}
	qs=qe=0;
	for(i=0;i<nnod;i++){
		if(ben[i]==0){
			q[qe]=i;
			qe++;
		}
	}
	while(qs<qe){
		for(i=en[q[qs]];i<en[q[qs]+1];i++){
			ben[elist[i]]--;
			if(ben[elist[i]]==0){
				q[qe]=elist[i];
				qe++;
			}
		}
		qs++;
	}
	if(qs!=nnod){
		printf("-1");
	}
	else{
		for(i=0;i<nnod;i++){
			if(q[i]<m){
				printf("%d ",q[i]+1);
			}
		}
	}
}