#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,M;vector<int>a[MAXN],d[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i].clear(),a[i].resize(M+1);For(i,1,N)For(j,1,M)a[i][j]=getc();
		vector<int>s;int ans=0;For(i,1,N)For(j,1,M)if((i+j&1)&&a[i][j])d[i+j>>1].push_back(i);
		For(i,1,(N+M>>1))
		{
			vector<int>&p=d[i],now;
			while(!s.empty()){int flag=0;while(!p.empty()&&p.back()>s.back())!flag&&(flag=p.back()),p.pop_back();if(flag||s.back()<N)now.push_back(flag?flag:s.back()+1);s.pop_back();}
			if(!p.empty())now.push_back(p.back()),ans++,p.clear();reverse(now.begin(),now.end());s=now;
		}
		s.clear();For(i,1,N)For(j,1,M)if(!(i+j&1)&&a[i][j])d[i+j>>1].push_back(i);
		For(i,1,(N+M>>1))
		{
			vector<int>&p=d[i],now;
			while(!s.empty()){int flag=0;while(!p.empty()&&p.back()>s.back())!flag&&(flag=p.back()),p.pop_back();if(flag||s.back()<N)now.push_back(flag?flag:s.back()+1);s.pop_back();}
			if(!p.empty())now.push_back(p.back()),ans++,p.clear();reverse(now.begin(),now.end());s=now;
		}
		cout<<ans<<'\n';
	}
	return 0;
}