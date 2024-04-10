#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N;vector<int>E[MAXN];vector<int>a;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){a.push_back(u);for(auto v:E[u])if(v!=f)dfs(v,u),a.push_back(u);}
int ask(vector<int>x){vector<int>vis(N+1);for(auto i:x)vis[i]=1;int cnt=0;For(i,1,N)cnt+=vis[i];cout<<"? "<<cnt<<' ';For(i,1,N)if(vis[i])cout<<i<<' ';cout<<endl;return get();}
int main()
{
	N=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}dfs(1,0);
	int mx=ask(a);while(a.size()>2){int mid=a.size()-1>>1;vector<int>b;For(i,0,mid)b.push_back(a[i]);if(ask(b)<mx){b.clear();For(i,mid,a.size()-1)b.push_back(a[i]);a=b;}else a=b;}
	cout<<"! "<<a[0]<<' '<<a[1]<<endl;return 0;
}