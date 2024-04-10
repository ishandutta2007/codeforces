#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 250001
int N,M;vector<vector<int> >a;
bool dfs(int dep)
{
	if(dep>2)return 0;
	For(i,1,N-1)
	{
		int cnt=0;For(j,0,M-1)cnt+=a[0][j]!=a[i][j];if(cnt>4)return 0;
		if(cnt>2){For(j,0,M-1)if(a[0][j]!=a[i][j]){int tmp=a[0][j];a[0][j]=a[i][j];if(dfs(dep+1))return 1;a[0][j]=tmp;}return 0;}
	}
	return 1;
}
int main(){cin>>N>>M;a.resize(N);For(i,0,N-1){a[i].resize(M);For(j,0,M-1)cin>>a[i][j];}if(dfs(0)){cout<<"Yes\n";For(i,0,M-1)cout<<a[0][i]<<' ';cout<<endl;}else cout<<"No\n";return 0;}