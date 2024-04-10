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
	int n,m;
	string x[1005];
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> x[i];
	}
	bool used[1005]={};
	while(1)
	{
		vector<int>bad;
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(used[j]) continue;
				if((x[i][j]-'a') < (x[i+1][j]-'a')) break;
				if((x[i][j]-'a') > (x[i+1][j]-'a'))
				{
					bad.pb(j);
					break;
				}
			}
		}
		if(bad.empty()) break;
		for(int i=0;i<bad.size();i++) used[bad[i]] = true;
	}
	cout << count(used,used+m,true) << endl;
}