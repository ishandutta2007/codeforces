#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 101
int N;vector<Pair>col[2];
int main()
{
	cin>>N;For(i,1,N)For(j,1,N)col[i+j&1].push_back({i,j});
	For(i,1,N*N)
	{
		bool vis[3]={1,1,1};int x;cin>>x;vis[x-1]=0;
		if(vis[0]&&!col[0].empty())cout<<1<<' '<<col[0].back().F<<' '<<col[0].back().S<<endl,col[0].pop_back();
		else if(vis[1]&&!col[1].empty())cout<<2<<' '<<col[1].back().F<<' '<<col[1].back().S<<endl,col[1].pop_back();
		else if(!col[0].empty())cout<<3<<' '<<col[0].back().F<<' '<<col[0].back().S<<endl,col[0].pop_back();
		else cout<<3<<' '<<col[1].back().F<<' '<<col[1].back().S<<endl,col[1].pop_back();
	}
	return 0;
}