#include<stdio.h>
#include<vector>
int n,m;
int edge[200100][2];
int chk[200100];
std::vector<int> el[200100];
int univ[200100];
int uc[200100];
int cent;
int ucc[200100];
long long int dp[200100];
void dfs(int x){
	chk[x]=1;
	uc[x]=univ[x];
	for(int i=0;i<el[x].size();i++){
		if(chk[el[x][i]]==0){
			dfs(el[x][i]);
			uc[x]+=uc[el[x][i]];
		}
	}
	if(uc[x]>=m&&cent==0)cent=x;
}
void sdfs(int x){
	chk[x]=2;
	ucc[x]=univ[x];
	dp[x]=0;
	for(int i=0;i<el[x].size();i++){
		if(chk[el[x][i]]!=2){
			sdfs(el[x][i]);
			ucc[x]+=ucc[el[x][i]];
			dp[x]+=dp[el[x][i]]+ucc[el[x][i]];
		}
	}
}
int main(){
	int i,j,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<2*m;i++){
		scanf("%d",&t);
		univ[t]=1;
	}
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
		univ[t]=1;
	}
	dfs(1);
	sdfs(cent);
	printf("%I64d",dp[cent]);
	return 0;
}