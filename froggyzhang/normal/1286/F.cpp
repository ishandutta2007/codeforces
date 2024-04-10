#include<bits/stdc++.h>
using namespace std;
#define N 20
typedef long long ll;
int n,dp[1<<N];
ll a[N];
vector<ll> Get(ll *a,int n){
	vector<ll> c(1<<n);
	for(int i=0;i<n;++i)c[0]-=a[i];
	for(int i=1;i<(1<<n);++i){
		c[i]=c[i^(i&-i)]+2*a[__builtin_ctz(i)];
	}
	return c;
}
bool check(int x){
	static ll c[N];
	static int m;
	m=0;
	ll sum=0;
	for(int i=0;i<n;++i){
		if(x>>i&1)c[m++]=a[i],sum+=a[i];
	}
	if(m==1&&!c[0])return true;
	if((sum&1)==(m&1))return false;
	int m1=m/2,m2=m-m1;
	auto A=Get(c,m1),B=Get(c+m1,m2);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int jb=1+2*(llabs(sum)<m);
	for(int i=0,j=0;i<(int)A.size();++i){
		while(j<(int)B.size()&&A[i]-B[j]>=m)++j;
		if(j==B.size())break;
		for(int k=j;k<(int)B.size()&&jb&&llabs(A[i]-B[k])<m;++k)--jb;
	}
	return !jb;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int s=1;s<(1<<n);++s){
		if(!dp[s]&&check(s)){
			for(int t=s;t<(1<<n);t=(t+1)|s){
				dp[t]=max(dp[t],dp[s^t]+1);	
			}
		}
	}
	cout<<n-dp[(1<<n)-1]<<'\n';
	return 0;
}