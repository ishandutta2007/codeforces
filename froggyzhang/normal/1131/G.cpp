#include<bits/stdc++.h>
using namespace std;
#define N 250020
#define M 10000010
typedef long long ll;
const ll inf=1e18;
int n,m,len[N],jb,st[M],top;
vector<int> a[N],c[N];
int h[M],l[M],r[M];
ll w[M],dp[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>len[i];
		a[i].resize(len[i]);
		c[i].resize(len[i]);
		for(int j=0;j<len[i];++j)cin>>a[i][j];
		for(int j=0;j<len[i];++j)cin>>c[i][j];
	}
	cin>>jb;
	m=0;
	while(jb--){
		int id,mul;
		cin>>id>>mul;
		for(int i=0;i<len[id];++i){
			++m;
			h[m]=a[id][i];
			w[m]=1LL*c[id][i]*mul;	
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	top=0;
	for(int i=1;i<=m;++i){
		l[i]=i;
		while(top&&i-h[i]<st[top])l[i]=l[st[top--]];
		st[++top]=i;
	}
	top=0;
	for(int i=m;i>=1;--i){
		r[i]=i;
		while(top&&i+h[i]>st[top])r[i]=r[st[top--]];
		st[++top]=i;	
	}
	st[top=1]=0;
	for(int i=1;i<=m;++i){
		while(top>1&&st[top-1]>=l[i]-1)--top;
		dp[i]=min(dp[i],dp[st[top]]+w[i]);
		dp[r[i]]=min(dp[r[i]],dp[i-1]+w[i]);
		while(top&&dp[i]<=dp[st[top]])--top;
		st[++top]=i;
	}
	cout<<dp[m]<<'\n';
	return 0;
}