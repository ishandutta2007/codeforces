#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 3001
int T,N,a[MAXN],pos[MAXN];vector<int>ans;
void opt(int x){For(i,1,x>>1)swap(a[i],a[x+1-i]),swap(pos[a[i]],pos[a[x+1-i]]);ans.push_back(x);}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],pos[a[i]]=i;bool flag=0;For(i,1,N)if(a[i]+i&1){flag=1;break;}if(flag){cout<<"-1\n";continue;}
		ans.clear();FOR(i,N,3){if(a[i]!=i||a[i-1]!=i-1)opt(pos[i]),opt(pos[i-1]-1),opt(pos[i-1]+1),opt(3),opt(i);i--;}
		cout<<ans.size()<<'\n';for(auto i:ans)cout<<i<<' ';cout<<'\n';
	}
	return 0;
}