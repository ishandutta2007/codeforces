#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int N,M,a[MAXN][MAXN],id[MAXN][MAXN],val[MAXN*MAXN];vector<int>E[MAXN*MAXN];const int tx[4]={0,1,0,-1},ty[4]={1,0,-1,0};
void add(int x,int y){E[x].push_back(y),E[y].push_back(x);}
void dfs(int u,int x){val[u]=5-x;for(auto v:E[u])if(!val[v])dfs(v,5-x);}
int main()
{
	cin>>N>>M;For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c=='X';}int tmp=0;For(i,1,N)For(j,1,M)id[i][j]=++tmp;
	For(i,1,N)For(j,1,M)if(a[i][j]){int cnt=0;For(k,0,3)cnt+=!a[i+tx[k]][j+ty[k]];if(cnt&1){cout<<"NO\n";return 0;}}
	For(i,1,N)For(j,1,M)if(a[i][j]){int lstx=0,lsty=0;For(k,0,3)if(!a[i+tx[k]][j+ty[k]])lstx&&lsty?add(id[lstx][lsty],id[i+tx[k]][j+ty[k]]),lstx=lsty=0:(lstx=i+tx[k],lsty=j+ty[k]);}
	For(i,1,N)For(j,1,M)if(!a[i][j]&&!val[id[i][j]])dfs(id[i][j],1);For(i,1,N)For(j,1,M)if(a[i][j]){For(k,0,3)val[id[i][j]]+=(!a[i+tx[k]][j+ty[k]])*val[id[i+tx[k]][j+ty[k]]];}
	cout<<"YES\n";For(i,1,N)For(j,1,M)cout<<val[id[i][j]]<<" \n"[j==M];return 0;
}