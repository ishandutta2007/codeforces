#include<bits/stdc++.h>
using namespace std;
#define N 505
int dp[N],n,x,i,to,k,vst[N],fm[N],ans,ps[N];
queue<int>q;
void solve(int n){
	if(!n){cout<<"! "<<ans;return ;}
	int i,o=(n-fm[n]+k)>>1,z=k-o,tot=0;
	cout<<"? ";
	for(i=1;o;++i){
		if(vst[i])ps[++tot]=i,--o;
	}
	for(i=1;z;++i){
		if(!vst[i])ps[++tot]=i,--z;
	}
	for(i=1;i<=tot;++i)cout<<ps[i]<<" ",vst[ps[i]]^=1;
	o=n-fm[n]+k>>1;
	cout<<"\n";cout.flush();
	cin>>o;ans^=o;
	solve(fm[n]);
}
int main(){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	q.push(0);
	while(q.size()){
		x=q.front();q.pop();
		for(i=max(k+x-n,0);i<=k&&i<=x;++i){
			to=x+k-i-i;
			if(!~dp[to])dp[to]=dp[x]+1,fm[to]=x,q.push(to);
		}
	}
	for(i=1;i<=n;++i)vst[i]=1;
	if(~dp[n])solve(n);else cout<<-1;
}