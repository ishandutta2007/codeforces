#include<cstdio>
#include<cstring>
#include<iostream>
typedef long long ll;
using namespace std;

int s[25];
ll f[25][170];
inline ll gao(int l,int sta,bool lim)
{
	if(!l) return !sta;
	if(!lim && f[l][sta]!=-1) return f[l][sta];
	
	int up=lim?s[l]:9;
	ll res=0;
	for(int i=0; i<=up; ++i)
	{
		if(sta<i) break;
		res+=gao(l-1,sta-i,lim&&i==up);
	}
	if(!lim) f[l][sta]=res;
	return res;
}

inline ll solve(ll m,int x)
{
	memset(f,-1,sizeof(f));
	
	int l=0;
	while(m)
	{
		s[++l]=m%10;
		m/=10;
	}
	
	return gao(l,x,1);
}

int main(void)
{
	ll n,s;
	cin>>n>>s;
	
	int a=min(n-s,162ll);
	ll ans=0;
	for(int i=1; i<=a; ++i)
		ans+=solve(n,i)-solve(i+s-1,i);
	
	cout<<ans;
	return 0;
}