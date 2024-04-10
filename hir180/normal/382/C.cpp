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
int main()
{
	int n;
	scanf("%d",&n);
	vector<ll>num;
	for(int i=0;i<n;i++)
	{
		ll x; scanf("%lld",&x);
		num.pb(x);
	}
	sort(num.begin(),num.end());
	if(n==1) puts("-1");
	else if(n==2)
	{
		vector<ll>ret;
		ret.pb(num[1]+num[1]-num[0]);
		ret.pb(num[0]-num[1]+num[0]);
		if((num[1]-num[0])%2==0)
		{
			ret.pb((num[1]+num[0])/2ll);
		}
		sort(ret.begin(),ret.end());
		ret.erase(unique(ret.begin(),ret.end()),ret.end());
		printf("%d\n",ret.size());
		for(int i=0;i<ret.size();i++)
		{
			printf("%lld%c",ret[i],i==ret.size()-1?'\n':' ');
		}
	}
	else
	{
		set<ll>se;
		for(int i=1;i<num.size();i++)
		{
			se.insert(num[i]-num[i-1]);
		}
		if(se.size()>=3) puts("0");
		else
		{
			vector<ll>v;
			set<ll>::iterator it;
			for(it=se.begin();it!=se.end();++it)
			{
				v.pb(*it);
			}
			if(v.size()==2 && v[0]*2!=v[1]) puts("0");
			else
			{
				if(v.size()==1)
				{
					if(num[0]-v[0]==num[n-1]+v[0])
					{
						puts("1");
						printf("%lld\n",num[n-1]+v[0]);
					}
					else
					{
					
					puts("2");
					printf("%lld ",num[0]-v[0]);
					printf("%lld\n",num[n-1]+v[0]);
					
					}
				}
				else
				{
					int cnt=0;
					for(int i=1;i<num.size();i++)
					{
						if(num[i]-num[i-1]==v[1])
						{
							cnt++;
						}
					}
					if(cnt!=1) puts("0");
					else
					{

					puts("1");
					for(int i=1;i<num.size();i++)
					{
						if(num[i]-num[i-1]==v[1])
						{
							printf("%lld\n",(num[i]+num[i-1])/2LL);
						}
					}

					}
				}
			}
		}
	}
}