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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
bool ok[2005][2005][11]={};
int main()
{
	string str[11];
	int lim[11][2];
	cin >> str[0];
	lim[0][0]=1;
	lim[0][1]=INF;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> str[i] >> lim[i][0] >> lim[i][1];
	map<string,pair<bool,int> > ma;
	int ans=0;
	int cov=0;
	for(int i=0;i<str[0].size();i++){ string f=""; for(int j=i;j<str[0].size();j++) { f.pb(str[0][j]); if(!ma[f].first) cov++; ma[f].first=true;}}
	if(!n) { cout << cov << endl; return 0;}
	for(int q=1;q<=n;q++)
	{
		for(int i=0;i<str[q].size();i++){ string f=""; for(int j=i;j<str[q].size();j++) { f.pb(str[q][j]); if(ma[f].first) ma[f].second++;}}
		map<string,pair<bool,int> >::iterator it;
		for(it=ma.begin();it!=ma.end();it++)
		{
			if(!(it->second.first && it->second.second>=lim[q][0] && it->second.second<=lim[q][1]))
			{
				ma[it->first].first=false;
			}
			else if(q==n)
			{
				ans++;
			}
			ma[it->first].second=0;
		}
	}
	cout << ans << endl;
}