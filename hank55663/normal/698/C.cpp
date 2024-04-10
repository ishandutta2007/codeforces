#include<bits/stdc++.h>
#define time Time
using namespace std;
double pos[1<<20];
double a[25];
double dp[1<<20];
int n,k;
long long  c[30][30];
long long  C(int a,int b){
	if(c[a][b]!=0)
	return c[a][b];
	if(a==b)
	return c[a][b]=1;
	if(b==0)
	return c[a][b]=1;
	return c[a][b]=C(a-1,b)+C(a-1,b-1);
}
void dfs(int d,int num,double sum){
	if(d==n)
	pos[num]=sum/(1-sum);//printf("%d %lf %lf\n",num,pos[num],sum);
	else
	{
		dfs(d+1,num*2+1,sum+a[d]);
		dfs(d+1,num*2,sum);
	}
}
/*void ddfs(int n){
	if(dp[n]!=1e9)
	return;
	dp[n]=pos[n];
	for(int i=0;i<n;i++)
	if(1<<i&n){
		ddfs(n-(1<<i));
		dp[n]-=dp[n-(1<<i)];
	}
	printf("%d %lf\n",n,dp[n]);
}*/
double dfs2(int d,int ddd,int num,int ask,int p){
	if(d==n){
		if(ask==p)
		return pos[num];
		else
		return 0;
	}
	if(d==ddd)
	return dfs2(d+1,ddd,num*2,ask,p);
	return dfs2(d+1,ddd,num*2,ask,p)+dfs2(d+1,ddd,num*2+1,ask,p+1);
	
}
main(){
	C(25,25);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	scanf("%lf",&a[i]);
	dfs(0,0,0);
	for(int i=0;i<(1<<20);i++)
	dp[i]=1e9;
//	ddfs((1<<n)-1);
	int print=0;
	for(int i=0;i<n;i++){
		if(print)
		printf(" ");
		print=1;
		if(a[i]>-1e-6&&a[i]<1e-6){
			printf("0.0");
			continue;
		}
		double ans[25]; 
		double kk=-1;
		//printf("%d %lf\n",k-1,ans);
		for(int j=1;j<k;j++){
			ans[j]=dfs2(0,i,0,j,0);
		//	printf("%d %lf\n",j,dfs2(0,i,0,j,0));
		}
		for(int j=2;j<k;j++)
			for(int k=1;k<j;k++)
				ans[j]-=ans[k]*C(n-k-1,j-k);
		double aa=1;
		for(int j=1;j<k;j++)
		aa+=ans[j];//printf("%.10lf\n",aa*a[i]);;
		printf("%.10lf",aa*a[i]);
	}
}