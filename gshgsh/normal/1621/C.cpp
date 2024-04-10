#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,p[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int x){cout<<"? "<<x<<endl;int y;cin>>y;return y;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)vis[i]=0;
		For(i,1,N)if(!vis[i])
		{
			vector<int>x;while(ask(i)!=i);x.push_back(i);
			do x.push_back(ask(i));while(x.back()!=i);
			x.pop_back();int M=x.size();For(i,0,M-1)p[x[i]]=x[(i+1)%M];
			for(auto i:x)vis[i]=1;
		}
		cout<<"! ";For(i,1,N)cout<<p[i]<<' ';cout<<endl;
	}
	return 0;
}