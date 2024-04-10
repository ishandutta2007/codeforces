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
#include <bitset>
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
#define N 10100
using namespace std;

short common[N][N],mx[N],c[N];
bitset<10100> isFriend[N];

void update(int x,int y)
{
	common[x][y]++;
	if (common[x][y]==mx[x]) c[x]++;
	else
		if (common[x][y]>mx[x]) c[x]=1, mx[x]=common[x][y];
	common[y][x]++;
	if (common[y][x]==mx[y]) c[y]++;
	else
		if (common[y][x]>mx[y]) c[y]=1, mx[y]=common[y][x];
}

int main()
{
	int m,n=0,a[10100],b[10100];
	map <string,int> person;
	string s,t;
	cin >> m;
	rep(i,m)
	{
		cin >> s >> t;
		if (!person.count(s)) person[s]=n++;
		if (!person.count(t)) person[t]=n++;
		a[i]=person[s]; b[i]=person[t];
		isFriend[a[i]][b[i]]=isFriend[b[i]][a[i]]=1;
	}
	
	rep(i,n) c[i]=n-1;
	rep(i,m) c[a[i]]--, c[b[i]]--;
	
	rep(i,m)
		fr(j,i+1,m-1)
		{
			int x=a[i],y=b[i],xx=a[j],yy=b[j];
			if (x==xx && !isFriend[y][yy]) update(y,yy);
			if (x==yy && !isFriend[y][xx]) update(y,xx);
			if (y==xx && !isFriend[x][yy]) update(x,yy);
			if (y==yy && !isFriend[x][xx]) update(x,xx);
		}
		
	cout << n << endl;
	for (map <string,int>::iterator it=person.begin();it!=person.end();it++)
		cout << it->first << ' ' << c[it->second] << endl;
}