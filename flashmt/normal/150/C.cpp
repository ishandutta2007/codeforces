#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,m,c,prob[300300];
long long x[300300],f[1500500],L[1500500],R[1500500],s[1500500];

void add(int nd,int l,int r,int x,long long v)
{
	if (l==r) 
	{
		s[nd]=v;
		if (v>0) f[nd]=L[nd]=R[nd]=v;
	}
	else
	{
		int m=(l+r)/2;
		if (x<=m) add(nd*2,l,m,x,v);
		else add(nd*2+1,m+1,r,x,v);
		s[nd]=s[nd*2]+s[nd*2+1];
		f[nd]=max(R[nd*2]+L[nd*2+1],max(f[nd*2],f[nd*2+1]));
		L[nd]=max(L[nd*2],s[nd*2]+L[nd*2+1]);
		R[nd]=max(R[nd*2+1],s[nd*2+1]+R[nd*2]);
	}
}

void get(int nd,int l,int r,int x,int y,long long &ff,long long &LL,long long &RR,long long &ss)
{
	if (l==x && r==y) 
	{
		ff=f[nd]; LL=L[nd]; RR=R[nd]; ss=s[nd];
		return;
	}
	int m=(l+r)/2;
	long long f1=0,f2=0,L1=0,L2=0,R1=0,R2=0,s1=0,s2=0;
	if (x<=m) get(nd*2,l,m,x,min(y,m),f1,L1,R1,s1);
	if (m<y) get(nd*2+1,m+1,r,max(x,m+1),y,f2,L2,R2,s2);
	ff=max(R1+L2,max(f1,f2));
	LL=max(L1,s1+L2);
	RR=max(R2,s2+R1);
	ss=s1+s2;
}

int main()
{
	long long ans=0;
	cin >> n >> m >> c;
	fr(i,1,n) cin >> x[i];
	fr(i,1,n-1) scanf("%d",&prob[i]);
	
	fr(i,1,n-1)
		add(1,1,n-1,i,(x[i+1]-x[i])*50-c*prob[i]);
		
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long ff,LL,RR,ss;
		get(1,1,n-1,a,b-1,ff,LL,RR,ss);
		ans+=ff;
	}
	printf("%.9lf\n",0.01*ans);
}