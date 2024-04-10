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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
int v[200005],a[200005],b[200005];
vector<int>A,B;
int bit[(1<<18)+5];
int f(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	for(int s=i;s<=(1<<18);s+=f(s)) bit[s]+=x;
}
int sum(int i)
{
	int res=0;
	for(int s=i;s>0;s-=f(s)) res+=bit[s];
	return res;
}
int bit2[(1<<18)+5];
void add2(int i,int x)
{
	for(int s=i;s<=(1<<18);s+=f(s)) bit2[s]+=x;
}
int sum2(int i)
{
	int res=0;
	for(int s=i;s>0;s-=f(s)) res+=bit2[s];
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);

	for(int i=0;i<n;i++)
	{
		int q = a[i];
		int qq = b[i];
		int f = sum(a[i]+1);
		int g = sum2(b[i]+1);
		v[n-1-i] += q+qq-f-g;
		add(a[i]+1,1);
		add2(b[i]+1,1);
	}
	for(int i=0;i<n;i++)
	{
		int f = v[i] / (i+1);
		v[i] -= f*(i+1);
		v[i+1] += f;
	}
	memset(bit,0,sizeof(bit));
	for(int i=n-1;i>=0;i--)
	{
		int lb = -1,ub = n-1;
		while(ub-lb > 1)
		{
			int mid = (lb+ub)/2;
			if(mid+1-sum(mid+1) >= v[i]+1) ub = mid;
			else lb = mid;
		}
		printf("%d%c",ub,i==0?'\n':' ');
		add(ub+1,1);
	}
}