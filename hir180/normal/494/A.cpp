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
int x[100005];
int v[100005];
int main()
{
	string s; cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == '(') x[i] = (i==0?0:x[i-1])+1;
		if(s[i] == ')') x[i] = (i==0?0:x[i-1])-1;
		if(s[i] == '#') x[i] = (i==0?0:x[i-1]);
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		v[i] = min((i==s.size()-1?INF:v[i+1]),x[i]);
	}if(v[0]<0){puts("-1"); return 0;}
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i] == '#')
		{
			if(v[s.size()-1] != v[i])
			{
				puts("-1"); return 0;
			}else break;
		}
	}
	int pre = 0; vector<int>res;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == '#')
		{
			if(pre >= v[i])
			{
				puts("-1"); return 0;
			}
			else
			{
				res.pb(1);
				pre++;
			}
		}
	}
	res[res.size()-1] += (x[s.size()-1]-pre);
	for(int i=0;i<res.size();i++)
	{
		printf("%d\n",res[i]);
	}
}