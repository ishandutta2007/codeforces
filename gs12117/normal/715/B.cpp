#include<stdio.h>
int n,m,l,s,t;
int p;
int chk[1010];
int edge[100100][3];
long long int nedge[100100][3];
long long int em[1010][1010];
long long int dp[1010];
long long int f(long long int x){
	int i,j,loc,cnt=0;
	for(i=0;i<m;i++){
		nedge[i][0]=edge[i][0];
		nedge[i][1]=edge[i][1];
		nedge[i][2]=edge[i][2];
		if(edge[i][2]==0){
			nedge[i][2]=x/p;
			if(cnt<x%p)nedge[i][2]++;
			cnt++;
		}
		em[edge[i][0]][edge[i][1]]=nedge[i][2];
		em[edge[i][1]][edge[i][0]]=nedge[i][2];
	}
	for(i=0;i<n;i++){
		chk[i]=0;
		dp[i]=1e15;
	}
	dp[s]=0;
	while(1){
		loc=-1;
		for(i=0;i<n;i++){
			if(chk[i]==0){
				if(loc==-1||dp[i]<dp[loc])loc=i;
			}
		}
		if(loc==-1)break;
		chk[loc]=1;
		for(i=0;i<n;i++){
			if(em[loc][i]!=0&&dp[i]>dp[loc]+em[loc][i])dp[i]=dp[loc]+em[loc][i];
		}
	}
	return dp[t];
}
int main(){
	int i,j;
	scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
	}
	p=0;
	for(i=0;i<m;i++){
		if(edge[i][2]==0)p++;
	}
	if(f(p)>l){
		printf("NO\n");
		return 0;
	}
	if(f(1e15)<l){
		printf("NO\n");
		return 0;
	}
	long long int ans=p;
	for(i=50;i>=0;i--){
		ans+=1LL<<i;
		if(f(ans)>l)ans-=1LL<<i;
	}
	f(ans);
	printf("YES\n");
	for(i=0;i<m;i++){
		printf("%I64d %I64d %I64d\n",nedge[i][0],nedge[i][1],nedge[i][2]);
	}
	return 0;
}