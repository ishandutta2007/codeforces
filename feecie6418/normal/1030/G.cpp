#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=2e6;
vector<pr> pk[2000005],b[2000005];
vector<int> p[2000005];
int n,a[200005],mus[200005],v[2000005],ans=1;
void Add(int x,int id){
	for(pr i:pk[x])b[i.first].push_back({i.second,id});
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=N;i++){
		if(v[i])continue;
		p[i].push_back(i);
		for(int j=i+i;j<=N;j+=i)p[j].push_back(i),v[j]=1;
	}
	for(int i=1;i<=N;i++){
		int t=i;
		for(int j:p[i]){
			int c=0;
			while(t%j==0)t/=j,c++;
			pk[i].push_back(pr(j,c));
		}
	}
	for(int i=n,j;i>=1;i=j-1){
		j=i;
		while(j>1&&a[j-1]==a[i])j--;
		if(j<i){
			Add(a[i],i),Add(a[i]-1,i-1);
			if(j<i-1)Add(a[i]-1,i-2);
			continue;
		}
		if(!b[a[i]].size())Add(a[i],i);
		else Add(a[i]-1,i);
	}
	for(int i=1;i<=N;i++){
		if(!b[i].size())continue;
		sort(b[i].begin(),b[i].end());
		for(int j=1;j<=b[i].back().first;j++)ans=1ll*ans*i%mod;
		if(b[i].size()==1||b[i].back().first!=b[i][b[i].size()-2].first){
			mus[b[i].back().second]=1;
		}
	}
	bool ok=0;
	for(int i=1;i<=n;i++)if(!mus[i])ok=1;
	cout<<ans+ok;
}