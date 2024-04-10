#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

vector <string> team;
int point[4],goalScore[4],goalConcede[4],result[4][4],match[4];

int find(string s)
{
	rep(i,sz(team))
		if (team[i]==s) return i;
	team.pb(s);
	return sz(team)-1;
}

bool cmp(int x,int y)
{
	if (point[x]!=point[y]) return point[x]>point[y];
	if (goalScore[x]-goalConcede[x]!=goalScore[y]-goalConcede[y]) 
		return goalScore[x]-goalConcede[x]>goalScore[y]-goalConcede[y];
	if (goalScore[x]!=goalScore[y]) return goalScore[x]>goalScore[y];
	return team[x]<team[y];
}

int ok(int a,int b,int x,int y)
{
	goalScore[a]+=x; goalScore[b]+=y;
	goalConcede[a]+=y; goalConcede[b]+=x;
	result[a][b]=x; result[b][a]=y;
	
	vector <int> order;
	rep(i,4) order.pb(i);
	sort(all(order),cmp);
	if (a==order[0] || a==order[1]) return 1;
	
	goalScore[a]-=x; goalScore[b]-=y;
	goalConcede[a]-=y; goalConcede[b]-=x;
	return 0;
}

int main()
{
	//freopen("c.in","r",stdin);
	rep(i,5)
	{
		string A,B,score;
		cin >> A >> B >> score;
		int a=find(A),b=find(B),x=score[0]-'0',y=score[2]-'0';
		if (x>y) point[a]+=3;
		else
			if (x<y) point[b]+=3;
			else point[a]++, point[b]++;
		goalScore[a]+=x; goalScore[b]+=y;
		goalConcede[a]+=y; goalConcede[b]+=x;
		result[a][b]=x; result[b][a]=y;
		match[a]++; match[b]++;
	}
	
	int berland=find("BERLAND"),opponent;
	rep(i,4)
		if (i!=berland && match[i]<3) opponent=i;
	point[berland]+=3;
	//rep(i,4) cout << team[i] << ' ' << point[i] << ' ' << goalScore[i] << ' ' << goalConcede[i] << endl;
		
	fr(dif,1,100)
		fr(y,0,100)
		{
			int x=y+dif;
			if (ok(berland,opponent,x,y)) 
			{
				cout << x << ':' << y << endl;
				return 0;
			}
		}
	
	puts("IMPOSSIBLE");
}