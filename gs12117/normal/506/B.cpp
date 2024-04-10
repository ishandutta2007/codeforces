#include<stdio.h>
int n,m;
int edge[100100][2];
int elist[200100];
int es[200100];
int en[100100];
int chk[100100];
int comp[100100];
int pn[100100];
int cn;
int q[100100];
int qs,qe;
int ans;
int flag;
void dfs(int loc){
	int i;
	chk[loc]=1;
	comp[cn]=loc;
	cn++;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==0){
			dfs(elist[i]);
		}
	}
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+10;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<m;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		es[en[edge[i][0]+1]]=1;
		pn[edge[i][0]]++;
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][1]+1]++;
	}
	ans=n;
	for(i=1;i<=n;i++){
		if(chk[i]==0){
			flag=0;
			cn=0;
			dfs(i);
			qe=0;
			for(j=0;j<cn;j++){
				if(pn[comp[j]]==0){
					q[qe]=comp[j];
					qe++;
				}
			}
			for(qs=0;qs<qe;qs++){
				for(j=en[q[qs]];j<en[q[qs]+1];j++){
					if(es[j]==0){
						pn[elist[j]]--;
						if(pn[elist[j]]==0){
							q[qe]=elist[j];
							qe++;
						}
					}
				}
			}
			for(j=0;j<cn;j++){
				if(pn[comp[j]]!=0){
					break;
				}
			}
			if(j==cn){
				ans--;
			}
		}
	}
	printf("%d",ans);
}