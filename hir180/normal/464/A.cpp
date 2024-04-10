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
	int n,p;
	string s;
	cin >> n >> p >> s;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=(s[i]-'a'+1);j<p;j++)
		{
			if(i >= 1 && ((s[i-1]-'a') == j))
			{
				continue;
			}
			if(i >= 2 && ((s[i-2]-'a') == j))
			{
				continue;
			}
			string res = "";
			for(int k=0;k<i;k++) res.pb(s[k]);
			res.pb(('a'+j));
			for(int k=i+1;k<n;k++)
			{
				for(int x=0;x<p;x++)
				{
					if(k >= 1 && ((res[k-1]-'a') == x))
					{
						continue;
					}
					if(k >= 2 && ((res[k-2]-'a') == x))
					{
						continue;
					}
					res.pb(('a'+x)); goto nxt;
				}
				goto fail; nxt:;
			}
			cout << res << endl; return 0; fail:;
		}
		
	}
	puts("NO");
}