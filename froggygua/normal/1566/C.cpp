#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
char s[N],t[N];
int n,dp[N];
inline int Mex(vector<char> A){
	int vis[4]={0,0,0,0};
	for(auto x:A)vis[x-'0']=1;
	for(int i=0;;++i)if(!vis[i])return i;
	assert(false);
}
void Solve(){
	cin>>n;
	cin>>(s+1)>>(t+1);
	dp[0]=0;
	dp[1]=Mex(vector<char>({s[1],t[1]}));
	for(int i=2;i<=n;++i){
		dp[i]=max(dp[i-1]+Mex(vector<char>({s[i],t[i]})),dp[i-2]+Mex(vector<char>({s[i],t[i],s[i-1],t[i-1]})));
	}
	cout<<dp[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}