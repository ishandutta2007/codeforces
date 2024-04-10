#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,M,K,pos[MAXN],a[MAXN],b[MAXN],c[MAXN],ans;vector<int>id[MAXN];
int main()
{
	cin>>N>>M>>K;For(i,1,N)cin>>a[i]>>b[i]>>c[i],pos[i]=i;For(i,1,M){int u,v;cin>>u>>v;pos[v]=max(pos[v],u);}For(i,1,N)id[pos[i]].push_back(i);priority_queue<int,vector<int>,greater<int> >q;
	For(i,1,N){while(K<a[i]&&!q.empty())ans-=q.top(),q.pop(),K++;if(K<a[i]){cout<<-1<<endl;return 0;}K+=b[i];for(auto j:id[i])K--,ans+=c[j],q.push(c[j]);while(K<0&&!q.empty())ans-=q.top(),q.pop(),K++;if(K<0){cout<<-1<<endl;return 0;}}
	cout<<ans<<endl;return 0;
}