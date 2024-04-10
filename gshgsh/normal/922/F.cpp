#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,K,siz[MAXN];bool vis[MAXN];
struct ssh{int a,b;friend bool operator<(const ssh&a,const ssh&b){return a.a>b.a||a.a==b.a&&a.b<b.b;}};
int main()
{
	cin>>N>>K;For(i,1,N)for(int j=i*2;j<=N;j+=i)siz[j]++;
	int sum=0;For(i,1,N)sum+=siz[i];if(K>sum){cout<<"No\n";return 0;}cout<<"Yes\n";
	while(sum-siz[N]>=K)sum-=siz[N--];vector<pair<int,int>>ssh;For(i,(N>>1)+1,N)ssh.push_back({siz[i],i});
	sort(ssh.begin(),ssh.end(),greater<pair<int,int>>());
	for(auto i:ssh)if(sum-i.first>=K)vis[i.second]=1,sum-=i.first;
	int cnt=0;For(i,1,N)cnt+=!vis[i];cout<<cnt<<'\n';For(i,1,N)if(!vis[i])cout<<i<<' ';cout<<'\n';return 0;
}