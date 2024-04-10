#include<stdio.h>
int n;
int edge[200100][2];
int en[200100];
int elist[400100];
int que[200100];
int chk[200100];
int root[200100];
int dist[200100];
int dpa[200100];
int dpb[200100];
int sn[200100];
int qs,qe;
int main(){
	int i,j,p;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+3;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<n-1;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][1]+1]++;
	}
	que[0]=1;
	qs=0;
	qe=1;
	while(qs<qe){
		chk[que[qs]]=1;
		for(i=en[que[qs]];i<en[que[qs]+1];i++){
			if(chk[elist[i]]==0){
				que[qe]=elist[i];
				root[que[qe]]=que[qs];
				dist[que[qe]]=dist[que[qs]]+1;
				qe++;
			}
		}
		qs++;
	}
	for(i=n-1;i>=0;i--){
		p=que[i];
		dpa[p]=0;
		dpb[p]=0;
		sn[p]=0;
		for(j=en[p];j<en[p+1];j++){
			if(root[elist[j]]==p){
				sn[p]+=sn[elist[j]];
			}
		}
		if(sn[p]==0){
			sn[p]=1;
			continue;
		}
		if(dist[p]%2==0){
			for(j=en[p];j<en[p+1];j++){
				if(root[elist[j]]==p){
					if(dpa[p]<sn[p]-sn[elist[j]]+dpa[elist[j]]){
						dpa[p]=sn[p]-sn[elist[j]]+dpa[elist[j]];
					}
					dpb[p]+=dpb[elist[j]]+1;
				}
			}
			dpb[p]--;
		}
		else{
			dpb[p]=99999999;
			for(j=en[p];j<en[p+1];j++){
				if(root[elist[j]]==p){
					dpa[p]+=dpa[elist[j]];
					if(dpb[p]>dpb[elist[j]]){
						dpb[p]=dpb[elist[j]];
					}
				}
			}
		}
	}
	printf("%d %d",dpa[1]+1,dpb[1]+1);
}