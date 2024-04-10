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
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int main()
{
	int n,m;
	cin >> n >> m;
	int a=0,b=0;
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		if(x%2 == 0) a++;
		else b++;
	}
	if(n == m)
	{
		cout << (b%2==0?"Daenerys":"Stannis") << endl;
		return 0;
	}
	if(n%2 == 0 && m%2 == 0)
	{
		cout << "Daenerys" << endl;
		return 0;
	}
	if(n%2 == 0 && m%2 == 1)
	{
		for(int i=0;i<n-m-1;i++)
		{
			if(i%2 == 0)
			{
				if(a) a--;
				else b--;
			}
			else
			{
				if(b) b--;
				else a--;
			}
		}
		cout << (b?"Stannis":"Daenerys") << endl;
		return 0;
	}
	if(n%2 == 1 && m%2 == 1)
	{
		for(int i=0;i<n-m-1;i++)
		{
			if(i%2 == 0)
			{
				if(a) a--;
				else b--;
			}
			else
			{
				if(b) b--;
				else a--;
			}
		}
		cout << (a?"Daenerys":"Stannis") << endl;
		return 0;
	}
	if(n%2 == 1 && m%2 == 0)
	{
		int c=a,d=b;
		for(int i=0;i<n-m-1;i++)
		{
			if(i%2 == 0)
			{
				if(a) a--;
				else b--;
			}
			else
			{
				if(b) b--;
				else a--;
			}
		}
		if(!a || !b)
		{
			cout << "Daenerys" << endl;
			return 0;
		}
		a=c,b=d;
		for(int i=0;i<n-m-1;i++)
		{
			if(i%2 == 1)
			{
				if(a) a--;
				else b--;
			}
			else
			{
				if(b) b--;
				else a--;
			}
		}
		if(!a || !b)
		{
			cout << "Daenerys" << endl;
			return 0;
		}
		cout << "Stannis" << endl;
	}
}