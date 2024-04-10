#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
int dp[605][605][27];
char c[605];
vector<int> v[27];
vector<int>::iterator lower[27][605],upper[27][605];
int DP(int l,int r,int k){
	if(l>r)return 0;
	if(dp[l][r][k]!=-1)return dp[l][r][k];
	if(k==26||lower[k][l]==upper[k][r]){//lower_bound(v[k].begin(),v[k].end(),l)==upper_bound(v[k].begin(),v[k].end(),r)){
		dp[l][r][k]=min(DP(l+1,r,26)+1,DP(l,r,c[l]-'a')+1);
		for(int i=l;i<r;i++){
			dp[l][r][k]=min(dp[l][r][k],DP(l,i,26)+DP(i+1,r,26));
		}
		return dp[l][r][k];
	}
	dp[l][r][k]=1e9;
	auto it=lower[k][l];//lower_bound(v[k].begin(),v[k].end(),l);
	auto it2=upper[k][r];//upper_bound(v[k].begin(),v[k].end(),r);
	int sum=DP(l,*it-1,26);
	while(it!=it2){
		dp[l][r][k]=min(dp[l][r][k],DP(l,*it-1,26)+DP(*it+1,r,k));
		it++;
	}
	//printf("%d %d %d %d\n",l,r,k,dp[l][r][k]);
	return dp[l][r][k];
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",c+1);
	for(int i=1;c[i]!=0;i++){
		v[c[i]-'a'].pb(i);
	}
	for(int i=0;i<26;i++){
		auto low=v[i].end(),up=v[i].end();
		for(int j=n;j>=1;j--){
			if(low!=v[i].begin()&&*(low-1)==j)low--;
			lower[i][j]=low;
			upper[i][j]=up;
			if(up!=v[i].begin()&&*(up-1)==j)up--;
		}
	}
	MEMS(dp);
	printf("%d\n",DP(1,n,26));
}