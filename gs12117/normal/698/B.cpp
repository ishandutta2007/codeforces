#include<stdio.h>
#include<vector>
int n;
int p[200100];
int chk[200100];
std::vector<int> ncng;
int rootv;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(i=1;i<=n;i++){
		if(chk[i]==0){
			j=i;
			while(chk[j]==0){
				chk[j]=i;
				j=p[j];
			}
			if(chk[j]==i){
				if(p[j]==j&&rootv==0){
					rootv=j;
				}
				else{
					ncng.push_back(j);
				}
			}
		}
	}
	if(rootv==0)rootv=ncng[0];
	for(i=0;i<ncng.size();i++){
		p[ncng[i]]=rootv;
	}
	printf("%d\n",ncng.size());
	for(i=1;i<=n;i++){
		printf("%d ",p[i]);
	}
	return 0;
}