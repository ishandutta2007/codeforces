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
#define mod 1000000007
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
ll bit[(1<<20)+5];
int f(int x){ return x&-x;}
void add(int i,ll x)
{
	for(int s=i;s<=(1<<20);s+=f(s)) bit[s]+=x;
}
ll sum(int i)
{
	ll res=0;
	for(int s=i;s>0;s-=f(s)) res+=bit[s];
	return res;
}
ll ret=0LL; int num[100005];
int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=n;i++)
	{
		ll v=sum(num[i])%mod;
		v=(v*num[i])%mod;
		v=(v+num[i])%mod;
		ret=(ret+v-sum(num[i])+sum(num[i]-1)+mod)%mod;
		add(num[i],v-sum(num[i])+sum(num[i]-1));
	}
	printf("%lld\n",ret);
}