//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
char v[5005][5005];
vector<int>nxt[5005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",&v[i]);
	for(int i=0;i<n;i++)
	{
		bool cur=false;
		int beg;
		for(int j=0;j<m;j++)
		{
			if(cur+v[i][j]-'0'==1)
			{
				if(!cur)
				{
					cur^=1;
					beg=j;
				}
				else
				{
					cur^=1;
					nxt[beg].pb(j-1);
				}
			}
		}
		if(cur) nxt[beg].pb(m-1);
	}
	vector<int>s; int ret=0;
	for(int i=0;i<m;i++)
	{
		if(nxt[i].empty()) continue;
		for(int j=0;j<nxt[i].size();j++) s.pb(nxt[i][j]);
		sort(s.begin(),s.end(),greater<int>());
		for(int j=s.size()-1;s[j]<i;j--) s.pop_back();
		int cur=0;
		while(cur<s.size())
		{
			int nxt=cur;
			while(nxt<s.size() && s[cur]==s[nxt]) nxt++;
			ret=max(ret,(s[cur]-i+1)*nxt); cur=nxt;
		}
	}
	printf("%d\n",ret);
}