#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
const int mod=1e9+7;
int n,m;
vector<int> G[1000005],g[1000005];
//G: g: 
vector<int> Solve(vector<int> ver){
	if(!ver.size())return ver;
	vector<int> isin(n+1),is(n+1),to(n+1);
	for(int i:ver)isin[i]=1;
	for(int i:ver){
		bool has=0;
		for(int j:G[i])if(isin[j])has|=is[j];
		if(!has){
			is[i]=1;
			for(int j:g[i])if(isin[j])to[j]=1;
		}
	}
	vector<int> nw;
	for(int i:ver){
		if(!is[i]&&!to[i])nw.push_back(i);
	}
	vector<int> o=Solve(nw);
	for(int i:o){
		for(int j:g[i])if(isin[j])is[j]=0;
		is[i]=1;
	}
	vector<int> ans;
	for(int i:ver)if(is[i])ans.push_back(i);
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		G[max(x,y)].push_back(min(x,y));
	}
	vector<int> vec;
	for(int i=1;i<=n;i++)vec.push_back(i);
	vector<int> p=Solve(vec);
	cout<<p.size()<<'\n';
	for(int i:p)cout<<i<<' ';
}