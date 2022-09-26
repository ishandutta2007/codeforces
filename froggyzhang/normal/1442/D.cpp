#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 3210
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
int n,k,t[N];
ll ans,w[N];
vector<int> a[N];
vector<ll> s[N],qwq;
void Get(int l,int r,vector<ll> &dp){
	for(int i=l;i<=r;++i){
		for(int j=k;j>=t[i];--j){
			dp[j]=max(dp[j],dp[j-t[i]]+w[i]);
		}
	}
}
void Solve(int l,int r,vector<ll> &A){
	if(l==r){
		for(int i=0;i<=min(k,t[l]);++i){
			ans=max(ans,A[k-i]+s[l][i]);
		}
		return;
	}
	int mid=(l+r)>>1;
	vector<ll> dpL=A,dpR=A;
	Get(l,mid,dpR);
	Get(mid+1,r,dpL);
	Solve(l,mid,dpL);
	Solve(mid+1,r,dpR);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		t[i]=read();
		a[i].resize(t[i]+1),s[i].resize(t[i]+1);
		for(int j=1;j<=t[i];++j){
			a[i][j]=read();
			s[i][j]=s[i][j-1]+a[i][j];
		}
		w[i]=s[i][t[i]];
	}
	qwq.resize(k+1);
	qwq[0]=0;
	Solve(1,n,qwq);
	printf("%lld\n",ans);
	return 0;
}