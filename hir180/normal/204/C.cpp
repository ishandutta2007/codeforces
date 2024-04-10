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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int n;
	cin >> n;
	ll sum=0;
	double ret=0.0;
	for(int i=1;i<=n;i++)
	{
		sum+=1LL*i*i;
	}
	string a,b;
	cin >> a >> b;
	vector<int>pos[26],pos2[26];
	vector<ll>back[26],back2[26];
	for(int i=0;i<n;i++) pos[a[i]-'A'].pb(i);
	for(int i=0;i<n;i++) pos2[b[i]-'A'].pb(i);
	for(int i=0;i<26;i++)
	{
		for(int j=pos[i].size()-1;j>=0;j--)
		{
			if(j == pos[i].size()-1) back[i].pb(pos[i][j]);
			else back[i].pb(back[i][back[i].size()-1]+1LL*pos[i][j]);
		}
		for(int j=pos2[i].size()-1;j>=0;j--)
		{
			if(j == pos2[i].size()-1) back2[i].pb(pos2[i][j]);
			else back2[i].pb(back2[i][back2[i].size()-1]+1LL*pos2[i][j]);
		}
	}
	//same
	for(int i=0;i<n;i++)
	{
		if(a[i] == b[i])
		{
			ret+=(double)(1LL*(i+1)*(n-i))/(double)sum;
		}
	}
	//right
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<pos[i].size();j++)
		{
			int x=pos[i][j];
			int p=upper_bound(pos2[i].begin(),pos2[i].end(),x)-pos2[i].begin();
			int id=pos2[i].size()-1-p;
			if(id<0) continue;
			ret+=(double)1LL*(x+1LL)/(double)sum*(double)(1LL*n*(id+1)-back2[i][id]);
		}
	}
	//left
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<pos2[i].size();j++)
		{
			int x=pos2[i][j];
			int p=upper_bound(pos[i].begin(),pos[i].end(),x)-pos[i].begin();
			int id=pos[i].size()-1-p;
			if(id<0) continue;
			ret+=(double)1LL*(x+1LL)/(double)sum*(double)(1LL*n*(id+1)-back[i][id]);
		}
	}
	printf("%.9f\n",ret);
}