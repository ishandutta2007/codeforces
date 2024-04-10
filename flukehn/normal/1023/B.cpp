#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	if(n>=k) n=k-1;
	ll l=k-n;
	ll r=k/2-(k&1?0:1);
	if(l>r) cout<<0;
	else cout<<r-l+1;
}