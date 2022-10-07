#include<stdio.h>
int n,m;
int eg[200100][3];
int flow[200100];
int en[200100];
int end[200100];
int edge[400100][3];
int edir[200100];
int q[200100];
int chk[200100];
int qs,qe;
int main(){
	int i,loc;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&eg[i][0],&eg[i][1],&eg[i][2]);
		flow[eg[i][0]]+=eg[i][2];
		flow[eg[i][1]]+=eg[i][2];
		en[eg[i][0]+1]++;
		en[eg[i][1]+1]++;
	}
	for(i=1;i<=n;i++){
		en[i]+=en[i-1];
		end[i]=en[i];
	}
	for(i=0;i<m;i++){
		edge[end[eg[i][0]]][0]=eg[i][1];
		edge[end[eg[i][0]]][1]=eg[i][2];
		edge[end[eg[i][0]]][2]=i;
		end[eg[i][0]]++;
		edge[end[eg[i][1]]][0]=eg[i][0];
		edge[end[eg[i][1]]][1]=eg[i][2];
		edge[end[eg[i][1]]][2]=i;
		end[eg[i][1]]++;
	}
	for(i=1;i<=n;i++){
		flow[i]/=2;
	}
	qs=0;
	qe=1;
	q[0]=1;
	for(;qs<qe;qs++){
		loc=q[qs];
		chk[loc]=1;
		for(i=en[loc];i<end[loc];i++){
			if(chk[edge[i][0]]==0){
				flow[edge[i][0]]-=edge[i][1];
				if(eg[edge[i][2]][0]!=loc)edir[edge[i][2]]=1;
				if(flow[edge[i][0]]==0&&edge[i][0]!=n){
					q[qe]=edge[i][0];
					qe++;
				}
			}
		}
	}
	for(i=0;i<m;i++){
		printf("%d\n",edir[i]);
	}
}