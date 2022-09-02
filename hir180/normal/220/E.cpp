//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
struct BIT
{
	ll bit[(1<<17)+5];
	int f(int x){ return x&-x;}
	void add(int i,ll x){
		for(int s=i;s<=(1<<17);s+=f(s)) bit[s]+=x;
	}
	int sum(int i){
		ll sum=0;
		for(int s=i;s>0;s-=f(s)) sum+=bit[s];
		return sum;
	}
}left,right;
int num[100005];
int main()
{
	srand((unsigned int)time(NULL));
	int n; ll k; scanf("%d %lld",&n,&k);
	vector<int>vec;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		vec.pb(num[i]);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=1;i<=n;i++)
	{
		num[i]=lower_bound(vec.begin(),vec.end(),num[i])-vec.begin();
		num[i]++;
	}
	ll val=0; int l2=2;
	for(int i=2;i<=n;i++)
	{
		val+=i-2-right.sum(num[i]);
		right.add(num[i],1);
	}
	ll ret=0LL;
	for(int i=1;i<n;i++)
	{
		val+=i-1-left.sum(num[i]);
		val+=right.sum(num[i]-1);
		left.add(num[i],1);
		while(l2<=n && val>k)
		{
			val-=left.sum((1<<17))-left.sum(num[l2]);
			val-=right.sum(num[l2]-1);
			right.add(num[l2],-1);
			l2++;
		}
		ret+=(n-l2+1);
		if(l2==i+1)
		{
			val-=left.sum((1<<17))-left.sum(num[l2]);
			val-=right.sum(num[l2]-1);
			right.add(num[l2],-1);
			l2++;
		}
	}
	printf("%lld\n",ret);
}