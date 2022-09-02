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
int n,k;
string x[100005];
set<string>se;
bool calcwin(string s)
{
	bool nxt = false;
	for(int i=0;i<26;i++)
	{
		s.pb('a'+i);
		nxt |= (se.find(s) != se.end());
		s.resize(s.size()-1);
		if(nxt) break;
	}
	if(!nxt) return 0;
	for(int i=0;i<26;i++)
	{
		s.pb('a'+i);
		if(se.find(s) != se.end())
		{
			if(!calcwin(s)) return 1;
		}
		s.resize(s.size()-1);
	}
	return 0;
}
bool calclose(string s)
{
	bool nxt = false;
	for(int i=0;i<26;i++)
	{
		s.pb('a'+i);
		nxt |= (se.find(s) != se.end());
		s.resize(s.size()-1);
		if(nxt) break;
	}
	if(!nxt) return 1;
	for(int i=0;i<26;i++)
	{
		s.pb('a'+i);
		if(se.find(s) != se.end())
		{
			if(!calclose(s)) return 1;
		}
		s.resize(s.size()-1);
	}
	return 0;
}
int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> x[i];
		string s = "";
		for(int j=0;j<x[i].size();j++)
		{
			s.pb(x[i][j]);
			se.insert(s);
		}
	}
	bool win = calcwin("");
	bool lose = calclose("");
	if(!win) puts("Second");
	else
	{
		if(lose) puts("First");
		else puts(k%2==1?"First":"Second");
	}
}