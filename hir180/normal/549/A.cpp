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
	string f[55];
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> f[i];
	int cnt = 0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			int w[30]={};
			w[(f[i][j]-'a')]++;
			w[(f[i][j+1]-'a')]++;
			w[(f[i+1][j]-'a')]++;
			w[(f[i+1][j+1]-'a')]++;
			if(w[0]==1 && w[2]==1 && w[4]==1 && w[5]==1)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}