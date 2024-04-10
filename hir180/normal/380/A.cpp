//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int num[100005];
ll len=0LL;
int main()
{
	int n;
	scanf("%d",&n);
	vector<P1>vec;
	for(int i=0;i<n;i++)
	{
		int t; scanf("%d",&t);
		if(t==1)
		{
			int a; scanf("%d",&a);
			vec.pb(mp(t,mp(a,-1)));
		}
		else
		{
			int a,b; scanf("%d %d",&a,&b);
			vec.pb(mp(t,mp(a,b)));
		}
	}
	vector<ll>query;
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		ll x; scanf("%lld",&x);
		query.pb(x);
	}
	int cur=0;
	for(int i=0;i<vec.size()&&cur!=query.size();i++)
	{
		if(vec[i].first==1)
		{
			len++;
			if(len<=100000LL)
			{
				num[len]=vec[i].s.f;
			}
			if(cur!=query.size() && len==(ll)query[cur])
			{
				printf("%d%c",vec[i].s.f,cur==query.size()-1?'\n':' ');
				cur++;
			}
		}
		else
		{
			int zan=0;
			int l=vec[i].s.f;
			int r=vec[i].s.s;
			ll gen=len;
			ll next=len+1LL*l*r;
			while(len<100000LL&&zan<l*r)
			{
				num[++len]=num[(zan%l)+1];
				zan++;
			}
			len=next;
			while(cur!=query.size() && query[cur]<=len)
			{
				ll dif=query[cur]-(gen+1LL);
				printf("%d%c",num[(dif%l)+1],cur==query.size()-1?'\n':' ');
				cur++;
			}
		}
	}
}