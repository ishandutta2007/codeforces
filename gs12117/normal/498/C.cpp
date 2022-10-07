#include<stdio.h>
#include<algorithm>
int n,m;
int a[110];
int b[110];
int pfl[10000];
int pfn;
int edge[110][2];
int ed[110];
int en[110];
int elist[210][2];
int chk[110];
int dchk[110];
int cback[110];
int dback[110];
int clist[110];
int dlist[110];
int cn,dn;
int ans;
int main(){
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
		for(j=2;j*j<=b[i];j++){
			if(b[i]%j==0){
				pfl[pfn]=j;
				pfn++;
				while(b[i]%j==0)b[i]/=j;
			}
		}
		if(b[i]!=1){
			pfl[pfn]=b[i];
			pfn++;
		}
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		edge[i][0]--;
		edge[i][1]--;
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+3;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<m;i++){
		elist[en[edge[i][0]+1]][0]=edge[i][1];
		elist[en[edge[i][0]+1]][1]=i;
		elist[en[edge[i][1]+1]][0]=edge[i][0];
		elist[en[edge[i][1]+1]][1]=i;
		en[edge[i][0]+1]++;
		en[edge[i][1]+1]++;
	}
	std::sort(pfl,pfl+pfn);
	for(i=0;i<pfn;i++){
		if(i==0||pfl[i]!=pfl[i-1]){
			for(j=0;j<n;j++){
				b[j]=0;
				k=a[j];
				while(k%pfl[i]==0){
					k/=pfl[i];
					b[j]++;
				}
			}
			for(j=0;j<m;j++){
				ed[j]=0;
			}
			for(j=0;j<n;j++){
				if(b[j]!=0){
					while(1){
						cn=0;
						for(k=0;k<n;k++){
							dchk[k]=0;
							chk[k]=0;
							if(j==k){
								chk[k]=1;
								clist[cn]=k;
								cn++;
							}
						}
						while(cn){
							dn=0;
							for(k=0;k<cn;k++){
								for(l=en[clist[k]];l<en[clist[k]+1];l++){
									if(b[elist[l][0]]!=0&&elist[l][0]!=j)break;
									if(dchk[elist[l][0]]==0){
										dchk[elist[l][0]]=1;
										dlist[dn]=elist[l][0];
										dback[elist[l][0]]=elist[l][1];
										dn++;
									}
								}
								if(l!=en[clist[k]+1])break;
							}
							if(k!=cn)break;
							cn=0;
							for(k=0;k<dn;k++){
								for(l=en[dlist[k]];l<en[dlist[k]+1];l++){
									if(ed[elist[l][1]]!=0&&chk[elist[l][0]]==0){
										chk[elist[l][0]]=1;
										clist[cn]=elist[l][0];
										cback[elist[l][0]]=elist[l][1];
										cn++;
									}
								}
							}
						}
						if(cn==0)break;
						b[j]--;
						b[elist[l][0]]--;
						ans++;
						ed[elist[l][1]]++;
						k=clist[k];
						while(k!=j){
							ed[cback[k]]--;
							k=edge[cback[k]][0]+edge[cback[k]][1]-k;
							ed[dback[k]]++;
							k=edge[dback[k]][0]+edge[dback[k]][1]-k;
						}
						if(b[j]==0)break;
					}
				}
			}
		}
	}
	printf("%d",ans);
}