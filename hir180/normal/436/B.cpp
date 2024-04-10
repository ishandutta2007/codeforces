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

int n,m,k;
char f[2005][2005];

int main()
{
	cin >> n >> m >> k;
	for(int i=0;i<n;i++) scanf("%s",&f[i]);
	
	for(int i=0;i<m;i++)
	{
		//(0,i)
		int tot = 0;
		for(int k = 1;;k++)
		{
			if(0 <= 0+k && 0+k < n && 0<= i-k && i-k < m)
			{
				if(f[0+k][i-k] == 'R') tot++;
			}
			else
			{
				break;
			}
		}
		for(int k = 1;;k++)
		{
			
			if(0 <= 0+k && 0+k < n && 0<= i+k && i+k < m)
			{
				if(f[0+k][i+k] == 'L') tot++;
			}
			else
			{
				break;
			}
		}
		for(int k = 2;k < n;k+=2)
		{
			if(f[k][i] == 'U') tot++;
		}
		printf("%d%c",tot,(i==m-1?'\n':' '));
	}
}