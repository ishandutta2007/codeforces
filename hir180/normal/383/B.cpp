//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//Thanks to scott_wu
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
int n,m;
P r[100005];
vector<P>p,np;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&r[i].f,&r[i].s);
	}
	sort(r,r+m);
	p.pb(mp(1,1));
	int le=0,ri=0;
	while(ri<m)
	{
		if(r[ri].f!=le+1 && !p.empty())
		{
			int l=p[0].f;
			p.clear();
			p.pb(mp(l,n));
		}
		int nx=ri;
		while(nx<m && r[nx].f==r[ri].f) nx++;
		np.clear();
		int last=1,cp=0,en;
		for(int i=ri;i<=nx;i++)
		{
			en=((i<nx)?r[i].s:n+1);
			while(cp<p.size()&&p[cp].s<last) cp++;
			if(cp<p.size()&&max(last,p[cp].f)<en)
			{
				np.pb(mp(max(last,p[cp].f),en-1));
			}
			last=r[i].s+1;
		}
		p=np;
		le=r[ri].f;
		ri=nx;
	}
	if(!p.empty()&&(le<n || p[p.size()-1].s==n)) cout << 2*n-2 << endl;
	else cout << -1 << endl;
}