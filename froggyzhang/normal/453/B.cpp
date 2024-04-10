#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
const int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,a[N];
int dp[N][1<<16],st[N],pre[N][1<<16];
void dfs(int u,int s){
	if(!u)return;
	dfs(u-1,s^st[pre[u][s]]);
	cout<<pre[u][s]<<' ';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=0;i<16;++i){
		for(int j=p[i];j<=60;j+=p[i]){
			st[j]|=1<<i;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<(1<<16);++j){
			for(int k=1;k<=59;++k){
				if(st[k]&j)continue;
				int w=abs(k-a[i])+dp[i-1][j];
				int &s=dp[i][j|st[k]];
				if(s>w)s=w,pre[i][j|st[k]]=k;
			}
		}
	}
	dfs(n,min_element(dp[n],dp[n]+(1<<16))-dp[n]);
	return 0;
}