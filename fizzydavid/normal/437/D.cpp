#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
#define ll long long
struct edge
{
	int x,y,w;
	bool operator<(const edge&b)const{return w>b.w;}
}e[100010];
int n,m,a[100011],f[100011],s[100011];
int find(int x){if(x==f[x])return x;f[x]=find(f[x]);return f[x];}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].y);
		e[i].w=min(a[e[i].x],a[e[i].y]);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y)ans+=1ll*e[i].w*s[x]*s[y],f[x]=y,s[y]+=s[x];
	}
	printf("%9lf\n",2.0*ans/n/(n-1));
// 	system("pause");
	return 0;
}