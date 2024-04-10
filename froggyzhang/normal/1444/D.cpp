#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
#define N 1005
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
int T,n,m,a[N],b[N];
bitset<N*N> dp[N];
bool Split(int *a,vector<int> *p){
	dp[0][0]=1;
	int sum=0;
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
		sum+=a[i];
	}
	if(sum&1||!dp[n][sum>>1])return false;
	for(int i=n,u=sum>>1;i>=1;--i){
		if(dp[i-1][u]){
			p[0].push_back(a[i]);
		}
		else{
			u-=a[i];
			p[1].push_back(a[i]);
		}
	}
	return true;
}
void Solve(){
	if(n^m){
		return (void)printf("No\n");
	}
	vector<int> A[2],B[2],tA,tB;
	if(!Split(a,A)||!Split(b,B))return (void)printf("No\n");
	if(A[0].size()>A[1].size())swap(A[0],A[1]);
	if(B[0].size()<B[1].size())swap(B[0],B[1]);
	sort(A[0].begin(),A[0].end(),greater<int>());
	sort(A[1].begin(),A[1].end(),greater<int>());
	sort(B[0].begin(),B[0].end());
	sort(B[1].begin(),B[1].end());
	for(auto x:A[0])tA.push_back(x);
	for(auto x:A[1])tA.push_back(-x);
	for(auto x:B[0])tB.push_back(x);
	for(auto x:B[1])tB.push_back(-x);
	printf("Yes\n");
	for(int i=0,x=0,y=0;i<n;++i){
		x+=tA[i];
		printf("%d %d\n",x,y);
		y+=tB[i];
		printf("%d %d\n",x,y);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		m=read();
		for(int i=1;i<=m;++i){
			b[i]=read();
		}
		Solve();
	}
	return 0;
}