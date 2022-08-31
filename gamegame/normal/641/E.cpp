#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int bit[100001];
int a[100001],t[100001],x[100001];
pair<int,int>sorti[100001];
int ans[100001];
vector<int>v[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> t[i] >> x[i];
		sorti[i]=make_pair(x[i],i);
		v[i].push_back(0);
	}
	sort(sorti+1,sorti+n+1);
	for(int i=1; i<=n ;i++){
		if(sorti[i].first==sorti[i-1].first) x[sorti[i].second]=x[sorti[i-1].second];
		else x[sorti[i].second]=i;
		v[x[sorti[i].second]].push_back(sorti[i].second); 
	}
	for(int i=1; i<=n ;i++){
		int m=v[i].size()-1;
		if(m==0) continue;
		for(int j=1; j<=m ;j++) sorti[j]=make_pair(t[v[i][j]],j);
		sort(sorti+1,sorti+m+1);
		for(int j=1; j<=m ;j++){
			if(sorti[j].first==sorti[j-1].first) t[v[i][sorti[j].second]]=t[v[i][sorti[j-1].second]];
			else t[v[i][sorti[j].second]]=j;
		}
		for(int j=1; j<=m ;j++){
			if(a[v[i][j]]==1) for(int k=t[v[i][j]]; k<=n ;k+=(k&-k)) bit[k]++;
			else if(a[v[i][j]]==2) for(int k=t[v[i][j]]; k<=n ;k+=(k&-k)) bit[k]--;
			else for(int k=t[v[i][j]]; k>=1 ;k-=(k&-k)) ans[v[i][j]]+=bit[k];
		}
		for(int j=1; j<=m ;j++){
			if(a[v[i][j]]==1) for(int k=t[v[i][j]]; k<=n ;k+=(k&-k)) bit[k]--;
			else if(a[v[i][j]]==2) for(int k=t[v[i][j]]; k<=n ;k+=(k&-k)) bit[k]++;
		}
	}
	for(int i=1; i<=n ;i++) if(a[i]==3) cout << ans[i] << '\n';
}