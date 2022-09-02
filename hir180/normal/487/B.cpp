#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int seg[(1<<18)][2]={};
void update(int k,int a)
{
	k+=(1<<17)-1;
	seg[k][0]=a; seg[k][1] = a;
	while(k>0)
	{
		k=(k-1)/2;
		seg[k][0]=max(seg[k*2+1][0],seg[k*2+2][0]);
		seg[k][1]=min(seg[k*2+1][1],seg[k*2+2][1]);
	}
}
P query(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return mp(-INF,INF);
	if(a<=l && r<=b) return mp(seg[k][0],seg[k][1]);
	else{
		P vl=query(a,b,k*2+1,l,(l+r)/2);
		P vr=query(a,b,k*2+2,(l+r)/2+1,r);
		return mp(max(vl.fi,vr.fi),min(vl.sc,vr.sc));
	}
}
int sg[(1<<18)];
void update2(int k,int a)
{
	k+=(1<<17)-1;
	sg[k] = a;
	while(k>0)
	{
		k=(k-1)/2;
		sg[k]=min(sg[k*2+1],sg[k*2+2]);
	}
}
int query2(int a,int b,int k,int l,int r)
{
	if(r<a || b<l || a>b) return INF;
	if(a<=l && r<=b) return sg[k];
	else{
		int vl=query2(a,b,k*2+1,l,(l+r)/2);
		int vr=query2(a,b,k*2+2,(l+r)/2+1,r);
		return min(vl,vr);
	}
}
int a[100005],n,s,l;
int main()
{
	scanf("%d%d%d",&n,&s,&l);
	fill(sg,sg+(1<<18),INF); update2(0,0);
	for(int i=0;i<(1<<18);i++) seg[i][1] = INF;
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]); update(i,a[i]);}
	for(int i=1;i<=n;i++)
	{
		int lb = 0;
		int ub = i;
		while(ub-lb > 1)
		{
			int mid = (lb+ub)/2;
			P get = query(mid,i,0,0,(1<<17)-1);
			if(get.fi-get.sc <= s) ub = mid;
			else lb = mid;
		}
//cout << ub << endl;
		int v = query2(ub-1,i-l,0,0,(1<<17)-1);
		if(v != INF)
		{
			update2(i,v+1); //cout << i << " " << v+1 << endl;
		}
	}
	cout << (sg[n+(1<<17)-1]>n?-1:sg[n+(1<<17)-1]) << endl;
}