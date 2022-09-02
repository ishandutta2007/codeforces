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
#include <cassert>
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
	ll a,b,w,x,c;
	scanf("%lld %lld %lld %lld %lld",&a,&b,&w,&x,&c);
	if(c<=a)
	{
		puts("0");
		return 0;
	}
	int cur=b,gen=x,big=w;
	int cyc=0,d;
	vector<int>vec;
	vector<int>rem;
	set<int>se;
	for(;;)
	{
		if(se.find(cur)!=se.end())
		{
			d=cur;
			break;
		}
		vec.pb(cur);
		se.insert(cur);
		int f=0;
		if(cur>=gen) cur-=gen;
		else { f=1; cur=big-(gen-cur);}
		rem.pb(1-f);
	}
	int beg;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]==d)
		{
			beg=i; break;
		}
	}
	for(int i=beg;i<vec.size();i++)
	{
		cyc+=rem[i];
	}
	ll dif=c-a;
	ll ope=0;
	for(int i=0;i<beg;i++)
	{
		dif-=rem[i];
		ope++;
		if(dif<=0)
		{
			printf("%lld\n",ope);
			return 0;
		}
	}
	assert(cyc);
	ll sp=(dif/cyc);
	ope+=sp*1LL*(vec.size()-beg);
	dif=dif%cyc;
	if(dif==0)
	{
		for(int i=vec.size()-1;i>=beg;i--)
		{
			if(!rem[i]) ope--;
			else break;
		}
		printf("%lld\n",ope);
		return 0;
	}
	for(int i=beg;i<vec.size();i++)
	{
		if(dif<=0)
		{
			printf("%lld\n",ope);
			return 0;
		}
		dif-=rem[i];
		ope++;
	}
		if(dif>=0)
		{
			printf("%lld\n",ope);
			return 0;
		}
}