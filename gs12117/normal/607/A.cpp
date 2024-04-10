#include<stdio.h>
#include<algorithm>
int n;
struct bc{
	int a,b;
	bool operator<(const bc&r)const{
		return a<r.a;
	}
};
bc d[100100];
int ans;
int dp[100100];
int bsrc(int x){
	int i,j;
	j=0;
	for(i=18;i>=0;i--){
		j+=1<<i;
		if(j>n||d[j-1].a>=x)j-=1<<i;
	}
	return j;
}
int main(){
	int i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&d[i].a,&d[i].b);
	}
	std::sort(d,d+n);
	ans=0;
	dp[0]=0;
	for(i=0;i<n;i++){
		t=bsrc(d[i].a-d[i].b);
		dp[i+1]=dp[t]+1;
		if(dp[i+1]>ans)ans=dp[i+1];
	}
	printf("%d",n-ans);
	return 0;
}