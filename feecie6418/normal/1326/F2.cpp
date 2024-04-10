#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int g[20][20],n,q;
ll f[300005][20],a[20][300005],b[300005],fin[505],id,ans[300005];
map<vector<int>,int> mp;
vector<int> vec;
void Or(ll a[],int flag){
	for(int i=1;i<(1<<n);i<<=1)for(int j=0;j<(1<<n);++j)if(i&j)a[j]+=flag*a[i^j];
}
void dfs(int x,int sum){
	if(sum==n){
		for(int i=0;i<(1<<n);i++)b[i]=1;
		for(int i=0;i<x;i++)for(int j=0;j<(1<<n);j++)b[j]*=a[vec[i]][j];
		Or(b,-1),fin[mp[vec]=++id]=b[(1<<n)-1];
		return ;
	}
	for(int i=(!x?1:vec[x-1]);i<=n-sum;i++)vec.push_back(i),dfs(x+1,sum+i),vec.pop_back();
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch,g[i][j]=ch-'0';
		}
	}
	for(int i=0;i<n;i++)f[1<<i][i]=1;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++)if(i&(1<<j))for(int k=0;k<n;k++)if(g[j][k]&&!(i&(1<<k)))f[i+(1<<k)][k]+=f[i][j];
		for(int j=0;j<n;j++)if(i&(1<<j))a[__builtin_popcount(i)][i]+=f[i][j];
	}
	for(int i=1;i<=n;i++)Or(a[i],1);
	dfs(0,0);
	for(int i=0;i<(1<<n-1);i++){
		vector<int> t;
		for(int l=0,r;l<n;l=r+1){
			r=l;
			while((i&(1<<r))&&r<n)r++;
			t.push_back(r-l+1);
		}
		sort(t.begin(),t.end()),ans[i]=fin[mp[t]];
	}
	for(int i=1;i<(1<<n-1);i<<=1)for(int j=0;j<(1<<n-1);++j)if(i&j)ans[i^j]-=ans[j];
	for(int i=0;i<(1<<n-1);i++)cout<<(ll)ans[i]<<' ';
}