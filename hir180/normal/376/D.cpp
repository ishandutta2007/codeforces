//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
char f[5005];
vector<int>rightt[5005];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
			scanf("%s",f);
			int le;
			bool len=false;
			for(int j=0;j<m;j++)
			{
					if(!len && f[j]=='1')
					{
						len=true;
						le=j;
					}
					if(len && f[j]=='0')
					{
							len=false;
							rightt[le].pb(j-1);
					}
			}
			if(len)
			{
					rightt[le].pb(m-1);
			}
	}
	vector<int>s;
	int ret=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<rightt[i].size();j++) s.pb(rightt[i][j]);
		sort(s.begin(),s.end(),greater<int>());
		int ss=s.size()-1;
		for(int j=ss;j>=0;j--) if(s[j]<i) s.pop_back();
		int cur=0;
		int pointt=0;
		while(cur<s.size())
		{
			while(pointt<s.size() && s[cur]==s[pointt]) pointt++;
			ret=max(ret,(pointt)*(s[cur]-i+1));
			
			//printf("%d %d\n",(pointt-cur),(rightt[i][cur]-i+1));
			cur=pointt;
		}
	}
	printf("%d\n",ret);
	cin >> ret;
	
}