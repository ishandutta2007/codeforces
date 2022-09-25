#include<bits/stdc++.h>
using namespace std;
#define N 2030
const int mod=998244353;
typedef long long ll;
int n,k;
void Solve_1(){
	static int dp[N];
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			dp[j]=(dp[j]+dp[j-i])%mod;
		}
	}
	cout<<accumulate(dp+1,dp+n+1,0LL)%mod<<'\n';
}
void Solve_2(){
	static int dp[N];
	dp[0]=1;
	for(int i=1;i*(i+1)/2<=n;++i){
		for(int j=i*(i+1)/2;j<=n;++j){
			dp[j]=(dp[j]+dp[j-i*(i+1)/2])%mod;	
		}
	}
	cout<<accumulate(dp+1,dp+n+1,0LL)%mod<<'\n';
}
int a[66],ans;
int check(int m){
	static int c[6666666],_c[6666666];
	for(int i=1;i<=m;++i)c[i]=a[i];
	for(int i=1;i<k;++i){
		int _m=0,tot=0;
		for(int j=1;j<=m;++j){
			tot+=c[j]*j;
			if(tot>n)return 0;
		}
		for(int j=m;j>=1;--j){
			while(c[j]--)_c[++_m]=j;	
		}
		m=_m;
		memcpy(c,_c,sizeof(int)*(m+1));
	}
	return 1;
}
void dfs(int u,int res,int lim){
	if(u>1)ans+=check(u-1);
	if(!res)return;
	for(int i=1;i<=min(res,lim);++i){
		a[u]=i;dfs(u+1,res-i,i);	
	}
}
void Solve_3(){
	dfs(1,min(n,64),64);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	if(k==1)Solve_1();
	else if(k==2)Solve_2();
	else Solve_3();
	return 0;
}