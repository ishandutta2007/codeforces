#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int n,m;
map<string,string> to;
string name[2001],ip[2001],rec[2001],IP[2001];
int main()
{
	n=read();m=read();
	For(i,1,n)
	{
		cin>>name[i];cin>>ip[i];
		ip[i]=ip[i]+';';
		to[ip[i]]=name[i];
	}
	For(i,1,m)
	{
		cin>>rec[i];cin>>IP[i];
		cout<<rec[i]<<' '<<IP[i]<<" #"<<to[IP[i]]<<endl;
	}
}