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
#define maxN 1
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
#define oo 1000111222
using namespace std;
struct queen
{
	int x,y,id;
};

int n,d[500500],canAttack[100100],ans[9];
queen a[100100];

bool cmp(queen i,queen j)
{
	return i.x<j.x || (i.x==j.x && i.y<j.y);
}

void increase(int x,int y)
{
	canAttack[x]++; canAttack[y]++;
}

int main()
{
	int y,s;
	cin >> s >> n;
	rep(i,n) scanf("%d%d",&a[i].x,&a[i].y), a[i].id=i;
	memset(d,-1,sizeof(d));
	sort(a,a+n,cmp);
	rep(i,n) 
	{
		if (i && a[i-1].x==a[i].x) increase(a[i-1].id,a[i].id);
		if (d[a[i].y]>=0) increase(a[d[a[i].y]].id,a[i].id);
		d[a[i].y]=i;
	}
	rep(i,n) y=a[i].y, a[i].y+=a[i].x, a[i].x-=y;
	memset(d,-1,sizeof(d));
	sort(a,a+n,cmp);
	rep(i,n) 
	{
		if (i && a[i-1].x==a[i].x) increase(a[i-1].id,a[i].id);
		if (d[a[i].y]>=0) increase(a[d[a[i].y]].id,a[i].id);
		d[a[i].y]=i;
	}
	rep(i,n) ans[canAttack[i]]++;
	rep(i,9) cout << ans[i] << ' ';
	puts("");
}