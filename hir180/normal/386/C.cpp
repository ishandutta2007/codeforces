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
#define rep(i,x) for(int i=0;i<x;i++)
vector<int>nex[300005];
vector<int>pos[26];
ll ret[28]={};
char str[300005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%s",&str);
	memset(nex,-1,sizeof(nex));
	int l=strlen(str);
	for(int i=0;i<l;i++)
	{
		pos[str[i]-'a'].pb(i);
	}
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<26;j++)
		{
			int s=lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
			if(s!=pos[j].size()) nex[i].pb(pos[j][s]);
		}
	}
	for(int i=0;i<l;i++)
	{
		sort(nex[i].begin(),nex[i].end());
		int pos=i; int beg=1;// cout << nex[i].size() << endl;
		for(int j=1;j<nex[i].size();j++)
		{//cout << nex[i][j] << " " << pos << endl;
			ret[beg++]+=nex[i][j]-pos;
			pos=nex[i][j];
		}
		ret[beg]+=l-pos;
	}
	int f=0;
	for(int i=1;i<=27;i++)
	{
		if(!ret[i]) { cout << i-1 << endl; break;}
	}
	for(int i=1;i<=26;i++)
	{
		if(ret[i]) cout << ret[i] << endl;
	}
}