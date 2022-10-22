#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define Fair pair<Pair,Pair>
#define F first
#define S second
#define MAXN 100001
int T,N;vector<int>E[MAXN];vector<Fair>ans;
int dfs(int u,int f){int res=u,cnt=0;for(auto v:E[u])if(v!=f){int tmp=dfs(v,u);if(!tmp)continue;cnt++;if(cnt==1)res=tmp;else if(cnt==2)ans.push_back({{u,f},{res,tmp}}),res=0;else ans.push_back({{u,v},{v,tmp}});}return res;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)E[i].clear();ans.clear();For(i,1,N-1){int u,v;cin>>u>>v;E[u].push_back(v),E[v].push_back(u);}
		int x=1;while(E[x].size()!=1)x++;int tmp=dfs(x,0);cout<<ans.size()<<endl;for(auto i:ans)cout<<i.F.F<<' '<<i.F.S<<' '<<tmp<<' '<<i.S.F<<endl,tmp=i.S.S;
	}
	return 0;
}