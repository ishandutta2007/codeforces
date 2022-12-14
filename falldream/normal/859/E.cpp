#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#define MN 200000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5],now=0,b[MN+5],num[MN+5],mark[MN+5],ans=1,vis[MN+5];
vector<int> v[MN+5];

int Dfs(int x)
{
	vis[x]=now;
	if(x==b[x]) return -2;
	if(!b[x]) return 0;
	if(mark[b[x]]) return 0;
	if(vis[b[x]]==now) return -1;
	if(vis[b[x]]>0) return 0;
	else return Dfs(b[x]);
}

void Mark(int x)
{
//	cout<<"Mark"<<x<<endl;
	mark[x]=1;
	if(!mark[b[x]]) Mark(b[x]);	
}
int Num;
int Solve(int x)
{
	++Num;
	for(int i=0;i<v[x].size();++i) Solve(v[x][i]);
//	cout<<"Solve"<<x<<endl;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[a[i]]=read(),v[b[a[i]]].push_back(a[i]);
	for(int i=1,t;i<=n;++i) if(!mark[a[i]]&&!vis[a[i]]&&(++now,t=Dfs(a[i]))<=-1) 
		Mark(a[i]),ans=(t==-2?1:2)*ans%mod;
	for(int i=1;i<=n<<1;++i) if(!mark[i]&&v[i].size()&&!b[i])
	{
		Num=0;
		int st=Solve(i);		
	//	cout<<Num<<endl;
		ans=1LL*ans*Num%mod;
	}
	cout<<ans;
	return 0;
}