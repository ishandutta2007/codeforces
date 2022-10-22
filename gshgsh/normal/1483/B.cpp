#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],nxt[MAXN];bool vis[MAXN];int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;queue<int>q;For(i,1,N)cin>>a[i],vis[i]=0,nxt[i]=i%N+1,q.push(i);
		vector<int>ans;while(!q.empty()){int x=q.front();q.pop();if(!vis[x]&&GCD(a[x],a[nxt[x]])==1)vis[nxt[x]]=1,ans.push_back(nxt[x]),nxt[x]=nxt[nxt[x]],q.push(x);}
		cout<<ans.size()<<' ';for(auto i:ans)cout<<i<<' ';cout<<endl;
	}
	return 0;
}