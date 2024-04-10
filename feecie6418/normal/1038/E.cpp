#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Solve1{
	int n,a[5],used[105],useb[5][5],ans=0;
	struct E{
		int to,v,id;
	};
	struct Bonus{
		int x,y,z;
	};
	vector<E> val[5][5],g[5];
	vector<Bonus> b[5];
	int dfs(int x){
		int ret=0,clax=a[x],p=0;
		vector<Bonus> cl;
		if(a[x])ret+=a[x],a[x]=0;
		for(Bonus i:b[x])if(!useb[i.x][i.y])useb[i.x][i.y]=1,ret+=i.z,cl.push_back(i);
		for(E i:g[x]){
			if(used[i.id])continue;
			used[i.id]=1,p=max(p,dfs(i.to)+i.v),used[i.id]=0;
		}
		a[x]=clax;
		for(Bonus i:cl)useb[i.x][i.y]=0;
		return ret+p;
	}
	void Solve(){
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>z>>y;
			if(x>y)swap(x,y);
			if(x^y)val[x][y].push_back({0,z,i});
			else a[x]+=z;
		}
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=4;j++){
				sort(val[i][j].begin(),val[i][j].end(),[](E i,E j){return i.v<j.v;});
				int t=2-(val[i][j].size()&1),s=0;
				while(val[i][j].size()>t)s+=val[i][j].back().v,val[i][j].pop_back();
				if(s)b[i].push_back({i,j,s}),b[j].push_back({i,j,s});
				for(E e:val[i][j])g[i].push_back({j,e.v,e.id}),g[j].push_back({i,e.v,e.id});
			}
		}
		for(int i=1;i<=4;i++)ans=max(ans,dfs(i));
		cout<<ans<<endl;
	}
}
int main(){
	Solve1::Solve();
}