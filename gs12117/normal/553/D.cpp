#include<stdio.h>
int n,m,p;
int pl[100100];
int edge[100100][2];
int en[100100];
int elist[200100];
int chk[100100];
int sleft[100100];
int q[100100];
int qs,qe;
int f(double x){
	int i;
	for(i=1;i<=n;i++){
		chk[i]=0;
		sleft[i]=en[i+1]-en[i];
	}
	qs=0;
	qe=0;
	for(i=0;i<p;i++){
		chk[pl[i]]=1;
		q[qe]=pl[i];
		qe++;
	}
	while(qs<qe){
		for(i=en[q[qs]];i<en[q[qs]+1];i++){
			sleft[elist[i]]--;
			if(chk[elist[i]]==0&&sleft[elist[i]]<(en[elist[i]+1]-en[elist[i]])*x){
				chk[elist[i]]=1;
				q[qe]=elist[i];
				qe++;
			}
		}
		qs++;
	}
	if(qe==n)return 0;
	return 1;
}
int main(){
	int i;
	double j,k;
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<p;i++){
		scanf("%d",&pl[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+5;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<m;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][1]+1]++;
	}
	k=0;
	j=1;
	for(i=0;i<200;i++){
		j/=2;
		if(f(k+j)==1){
			k=k+j;
		}
	}
	f(k);
	int ans=0;
	for(i=1;i<=n;i++){
		if(chk[i]==0){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++){
		if(chk[i]==0){
			printf("%d ",i);
		}
	}
}