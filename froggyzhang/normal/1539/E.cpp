#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,p0[N],p1[N],k[N],l1[N],r1[N],l2[N],r2[N],dp[N][2],pre[N][2];
set<pair<int,int> > s0,s1;
void dfs(int u,int t){
	if(!u)return;
	dfs(u-1,pre[u][t]);
	printf("%d ",t);	
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		l1[i]=read(),r1[i]=read();
		l2[i]=read(),r2[i]=read();
	}
	s0.insert(make_pair(0,0));
	s1.insert(make_pair(0,0));
	for(int i=1;i<=n;++i){
		s0.insert(make_pair(k[i],i));
		s1.insert(make_pair(k[i],i));
		while(!s0.empty()&&s0.begin()->first < l1[i]){
			p0[s0.begin()->second]=i-1;
			s0.erase(s0.begin());
		}
		while(!s0.empty()&&s0.rbegin()->first > r1[i]){
			p0[s0.rbegin()->second]=i-1;
			s0.erase(--s0.end());
		}
		while(!s1.empty()&&s1.begin()->first < l2[i]){
			p1[s1.begin()->second]=i-1;
			s1.erase(s1.begin());
		}
		while(!s1.empty()&&s1.rbegin()->first > r2[i]){
			p1[s1.rbegin()->second]=i-1;
			s1.erase(--s1.end());
		}
	}
	while(!s0.empty())p0[s0.begin()->second]=n,s0.erase(s0.begin());
	while(!s1.empty())p1[s1.begin()->second]=n,s1.erase(s1.begin());
	dp[0][0]=p1[0];
	dp[0][1]=p0[0];
	for(int i=1;i<=n;++i){
		dp[i][0]=dp[i][1]=-1;
		// 0:
		if(dp[i-1][0]>=i&&p0[i]>=i){
			if(dp[i-1][0]>dp[i][0]){
				dp[i][0]=dp[i-1][0];
				pre[i][0]=0;
			}
		}
		if(dp[i-1][1]>=i-1&&p1[i-1]>=i&&p0[i]>=i){
			if(p1[i-1]>dp[i][0]){
				dp[i][0]=p1[i-1];
				pre[i][0]=1;
			}
		}
		// 1:
		if(dp[i-1][1]>=i&&p1[i]>=i){
			if(dp[i-1][1]>dp[i][1]){
				dp[i][1]=dp[i-1][1];
				pre[i][1]=1;
			}
		}
		if(dp[i-1][0]>=i-1&&p0[i-1]>=i&&p1[i]>=i){
			if(p0[i-1]>dp[i][1]){
				dp[i][1]=p0[i-1];
				pre[i][1]=0;
			}
		}
		if(!~dp[i][0]&&!~dp[i][1]){
			return !printf("No\n");
		}
	}
	printf("Yes\n");
	if(~dp[n][0])dfs(n,0);
	else dfs(n,1);
	return 0;
}