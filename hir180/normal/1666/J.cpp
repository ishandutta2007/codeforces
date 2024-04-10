#include <bits/stdc++.h>
#define SIZE 205
#define INF 100000000000000000LL
using namespace std;
typedef long long int ll;

int A[SIZE][SIZE];
ll rt[SIZE][SIZE];
ll dp[SIZE][SIZE];
int tp[SIZE][SIZE];
int par[SIZE];

ll get(int a,int b,int c,int d){
	ll ret=rt[b][d];
	if(a>0) ret-=rt[a-1][d];
	if(c>0) ret-=rt[b][c-1];
	if(a>0&&c>0) ret+=rt[a-1][c-1];
	return ret;
}
void dfs(int s,int t,int p){
	if(s>t) return;
	int k=tp[s][t];
	par[k]=p;
	dfs(s,k-1,k);
	dfs(k+1,t,k);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			rt[i][j]=A[i][j];
			if(i>0) rt[i][j]+=rt[i-1][j];
			if(j>0) rt[i][j]+=rt[i][j-1];
			if(i>0&&j>0) rt[i][j]-=rt[i-1][j-1];
		}
	}
	for(int L=1;L<=n;L++){
		for(int i=0;i+L<=n;i++){
			int j=i+L-1;
			dp[i][j]=0;
			if(i>0) dp[i][j]+=get(i,j,0,i-1);
			if(j+1<n) dp[i][j]+=get(i,j,j+1,n-1);
			ll s=INF;
			for(int k=i;k<=j;k++){
				ll sum=0;
				if(k>i) sum+=dp[i][k-1];
				if(k<j) sum+=dp[k+1][j];
				if(s>sum){
					s=sum;
					tp[i][j]=k;
				}
			}
			dp[i][j]+=s;
		}
	}
	dfs(0,n-1,-1);
	for(int i=0;i<n;i++) printf("%d ",par[i]+1);puts("");
	//printf("%lld\n",dp[0][n-1]);
}