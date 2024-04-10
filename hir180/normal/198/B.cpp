//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
int d[200005][2];
int main()
{
	srand((unsigned int)time(NULL));
	int n,k;
	cin >> n >> k;
	string le[2];
	cin >> le[0] >> le[1];
	for(int i=0;i<2;i++) while(le[i].size()<200000) le[i].pb('-');
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<2;j++)
		{
			d[i][j]=INF;
		}
	}
	priority_queue<P1,vector<P1>,greater<P1> >que;
	d[1][0]=1;
	que.push(mp(1,mp(1,0)));
	while(!que.empty())
	{
		P1 p=que.top(); que.pop();
		if(p.fi != d[p.sc.fi][p.sc.sc]) continue;
		int time=p.fi;
		int height=p.sc.fi;
		int side=p.sc.sc;
		//down
		if(time+1 <= height-1 && 1<=height-1 && le[side][height-2]=='-' && d[height-1][side]>time+1)
		{
			d[height-1][side]=time+1;
			if(height-1<=n) que.push(mp(time+1,mp(height-1,side)));
		}
		//up
		if(time+1 <= height+1 && 1<=height+1 && le[side][height]=='-' && d[height+1][side]>time+1)
		{
			d[height+1][side]=time+1;
			if(height+1<=n) que.push(mp(time+1,mp(height+1,side)));
		}
		//jump to another wall
		if(time+1 <= height+k && 1<=height+k && le[1-side][height+k-1]=='-' && d[height+k][1-side]>time+1)
		{
			d[height+k][1-side]=time+1;
			if(height+k<=n) que.push(mp(time+1,mp(height+k,1-side)));
		}
	}
	for(int i=n+1;i<=200000;i++)for(int j=0;j<2;j++) if(d[i][j]!=INF) { cout << "YES" << endl; return 0;}
	cout << "NO" << endl;
}