#include<stdio.h>
int n,m;
int ans;
int bns;
int jcard[110][2];
int ccard[110];
int ccda[8100];
int ccdb[8100];
int jdcd[8100];
int jacd[8100];
char tmp[10];
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s%d",tmp,&jcard[i][0]);
		if(tmp[0]=='A'){
			jcard[i][1]=0;
			jacd[jcard[i][0]]++;
		}
		else{
			jcard[i][1]=1;
			jdcd[jcard[i][0]]++;
		}
	}
	for(i=0;i<m;i++){
		scanf("%d",&ccard[i]);
		ans+=ccard[i];
		ccda[ccard[i]]++;
		ccdb[ccard[i]]++;
	}
	for(i=0;i<8010;i++){
		for(k=0;k<jdcd[i];k++){
			for(j=i+1;j<8010;j++){
				if(ccda[j]!=0){
					ccda[j]--;
					ans-=j;
					break;
				}
			}
			if(j==8010)ans=-1;
		}
	}
	for(i=0;i<8010;i++){
		for(k=0;k<jacd[i];k++){
			for(j=i;j<8010;j++){
				if(ccda[j]!=0){
					ccda[j]--;
					ans-=i;
					break;
				}
			}
			if(j==8010)ans=-1;
		}
	}
	j=8010;
	for(i=0;i<8010;i++){
		while(jacd[i]!=0){
			while(j>=0&&ccdb[j]==0)j--;
			if(j<=i)break;
			ccdb[j]--;
			jacd[i]--;
			bns+=j-i;
		}
	}
	if(ans>bns)printf("%d",ans);
	else printf("%d",bns);
}