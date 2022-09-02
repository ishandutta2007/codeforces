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
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int>atk,def,ciel;
	for(int i=0;i<n;i++)
	{
		string s;
		int v;
		cin >> s >> v;
		if(s=="ATK")
		{
			atk.pb(v);
		}
		else
		{
			def.pb(v);
		}
	}
	sort(atk.begin(),atk.end());
	sort(def.begin(),def.end());
	for(int i=0;i<m;i++)
	{
		int x; scanf("%d",&x);
		ciel.pb(x);
	}
	sort(ciel.begin(),ciel.end(),greater<int>());
	int ret=0;
	for(int i=0;i<=min(ciel.size(),atk.size());i++)
	{
		//USE NO DEFs
		int sum=0;
		for(int j=0;j<i;j++)
		{
			if(atk[j]>ciel[i-1-j])
			{
				goto nxt;
			}
			else
			{
				sum+=(ciel[i-1-j]-atk[j]);
			}
		}
		ret=max(ret,sum);
	}
	nxt:;
		//USE ALL DEFs
		int beg=ciel.size()-1;
		int cur=0;
		bool used[105]={};
		int sum=0;
		while(beg>=0 && cur<def.size())
		{
			if(ciel[beg]>def[cur])
			{
				used[beg]=true;
				beg--;
				cur++;
			}
			else
			{
				beg--;
			}
		}
		if(cur!=def.size()) goto out;
		cur=atk.size()-1;
		for(int ii=0;ii<ciel.size();ii++)
		{
			if(used[ii]) continue; 
			if(cur>=0)
			{
				if(atk[cur]<=ciel[ii]) sum+=ciel[ii]-atk[cur--]; else goto out;
			}
			else
			{
				sum+=ciel[ii];
			}
		}
		ret=max(ret,sum); out:;
	printf("%d\n",ret);
}