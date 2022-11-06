#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,k,x;long long f[30][3005],sum[3005],ans;vector<int>v[3005];
void solve(int dep,int l,int r){
	
	if(l==r){
		long long Sum=0;int id=0;
		for(int j=0;j<=v[l].size();++j){
			ans=max(ans,Sum+f[dep][k-j]);
			if(j==k)break;
			if(j<v[l].size())Sum+=v[l][j];
		}
		return;
	}
	int mid=l+r>>1;
	for(int j=0;j<=k;++j)f[dep+1][j]=f[dep][j];
	for(int i=mid+1;i<=r;++i){
		for(int j=k;j>=v[i].size();--j){
			f[dep+1][j]=max(f[dep+1][j],f[dep+1][j-v[i].size()]+sum[i]);
		}
	}
	solve(dep+1,l,mid);
	for(int j=0;j<=k;++j)f[dep+1][j]=f[dep][j];	
	for(int i=l;i<=mid;++i){
		for(int j=k;j>=v[i].size();--j){
			f[dep+1][j]=max(f[dep+1][j],f[dep+1][j-v[i].size()]+sum[i]);
		}
	}
	solve(dep+1,mid+1,r);
}
int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i){
		int t=read();
		for(int j=1;j<=t;++j){
			x=read();
			v[i].push_back(x);
			sum[i]+=x;
		}
	}
	solve(1,1,n);cout<<ans<<"\n";
	return 0;
}