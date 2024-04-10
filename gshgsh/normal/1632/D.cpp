#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN],ans[MAXN];;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();vector<pair<int,pair<int,int>>>v;
	For(i,1,N)
	{
		for(auto&j:v)j.first=__gcd(j.first,a[i]);v.push_back({a[i],{i,i}});
		vector<pair<int,pair<int,int>>>now;for(auto j:v)if(now.empty()||j.first!=now.back().first)now.push_back(j);else now.back().second.second=j.second.second;v=now;
		bool flag=0;for(auto j:v)if(i-j.first+1>=j.second.first&&i-j.first+1<=j.second.second)flag=1;
		if(flag)ans[i]=1,v.clear();ans[i]+=ans[i-1];
	}
	For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;
}