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

int n,s,c3,c4,c5,best=oo,lcm=1,d3,d5,r3,r4,r5;

void check(int x,int y,int z)
{
	if (x>y || y>z || x>z) return;
	if (x<0) return;
	if (x*c3+y*c4+z*c5!=s) return;
	int f=abs(x*c3-y*c4)+abs(y*c4-z*c5);
	if (f<best)
	{
		best=f;
		r3=x; r4=y; r5=z;
	}
}

int main()
{
	int x;
	cin >> n >> s;
	rep(i,n) 
	{
		cin >> x;
		if (x==3) c3++; else if (x==4) c4++; else c5++;
	}
	
	while (lcm%c3 || lcm%c5) lcm++;
	d3=lcm/c3; d5=lcm/c5;
		
	for (int y=0;c4*y<=s;y++)
	{
		int t=s-y*c4,x,z,L=y*c4,R=t-L;
		if (L>R) swap(L,R);
		
		x=t/(c3+c5);
		int cannot=0;
		rep(i,c5+2) 
		{
			if (i>c5) cannot=1;
			if ((t-c3*x)%c5==0 || cannot) break;
			x--;
		}
		if (cannot) continue;
		z=(t-c3*x)/c5;
		if (x>y || y>z)
		{
			int need=max(0,(x-y)/d3);
			need=max(need,(y-z)/d5);
			x-=d3*need;
			z+=d5*need;
			while (x>y || y>z) x-=d3, z+=d5;
		}
		if (x<0) continue;
		
		check(x,y,z);
		
		R=min(R,x*c3);
		int ll=(L-c3*x)/lcm,rr=(R-c3*x)/lcm;
		while (c3*x+lcm*ll<L) ll++;
		while (c3*x+lcm*rr>R) rr--;

		x+=d3*ll; z=(t-c3*x)/c5;
		check(x,y,z);
		x-=d3; z=(t-c3*x)/c5;
		check(x,y,z);
	}
	if (best==oo) puts("-1");
	else cout << r3 << ' ' << r4 << ' ' << r5 << endl;
}