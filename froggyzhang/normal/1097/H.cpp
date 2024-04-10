#include<bits/stdc++.h>
using namespace std;
#define N 30030
#define M 65
typedef long long ll;
int d,m,gen[20],B[N],n,P;
bitset<N> all;
struct Data{
	ll val,len;
	bitset<N> pre,suf;
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.len=a.len+b.len;
		c.val=a.val+b.val;
		c.pre=a.pre,c.suf=b.suf;
		if(a.len<n-1)c.pre&=(b.pre>>a.len)|(all<<n-1-a.len);
		if(b.len<n-1)c.suf&=(a.suf<<b.len)|(all>>n-1-b.len);
		if(c.len>=n){
			auto tmp=a.suf&b.pre;
			if(a.len<n-1)tmp&=all>>n-1-a.len;
			if(b.len<n-1)tmp&=all<<n-1-b.len;
			c.val+=tmp.count();
		}
		return c;
	}
}dp[M][M],E;
int h[M],len;
Data dfs(int u,int s,bool lim){
	if(!u||!lim){
		return dp[u][s];
	}
	Data ans=E;
	int t=lim?h[u]:d-1;
	for(int i=0;i<=t;++i){
		ans=ans+dfs(u-1,(s+gen[i])%m,lim&(t==i));	
	}
	return ans;
}
ll Query(ll p){
	if(p<0)return 0;
	len=0;
	while(p)h[++len]=p%d,p/=d;
	return dfs(len,0,1).val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>d>>m;
	for(int i=0;i<d;++i){
		cin>>gen[i];
	}
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>B[i];	
	}
	for(int i=1;i<n;++i)all[i]=1;
	E.val=E.len=0;
	for(int i=1;i<n;++i)E.pre[i]=E.suf[i]=1;
	for(int i=0;i<m;++i){
		dp[0][i].val=(n==1&&i<=B[1]);
		dp[0][i].len=1;
		for(int j=1;j<n;++j){
			dp[0][i].pre[j]=i<=B[j+1];
			dp[0][i].suf[j]=i<=B[j];	
		}
	}
	P=1;
	while(pow(d,P)<=1e18+2)++P;
	for(int i=1;i<=P;++i){
		for(int j=0;j<m;++j){
			dp[i][j]=E;
			for(int c=0;c<d;++c){
				dp[i][j]=dp[i][j]+dp[i-1][(j+gen[c])%m];
			}
		}
	}
	ll l,r;
	cin>>l>>r;
	--l,--r;
	cout<<Query(r)-Query(l+n-2)<<'\n';
	return 0;
}