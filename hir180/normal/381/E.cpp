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
#define f first
#define rep(i,x) for(int i=0;i<x;i++)
#define s (1<<20)
class segtree
{
	public:
	int val[s*2];
	int le[s*2];
	int ri[s*2];
	void update(int pos,int x)
	{
		val[pos+s-1]=0;
		le[pos+s-1]=1-x;
		ri[pos+s-1]=x;
	}
	void up()
	{
		for(int i=s-2;i>=0;i--)
		{
			int add=min(le[i*2+1],ri[i*2+2]);
			val[i]=val[i*2+1]+val[i*2+2]+add;
			le[i]=le[i*2+1]+le[i*2+2]-add;
			ri[i]=ri[i*2+1]+ri[i*2+2]-add;
		}
	}
	P1 query(int a,int b,int k,int l,int r)
	{
		P1 p=mp(0,mp(0,0));
		if(r<a || b<l) return p;
		if(a<=l && r<=b)
		{
			return mp(val[k],mp(le[k],ri[k]));
		}
		P1 x=query(a,b,k*2+1,l,(l+r)/2);
		P1 y=query(a,b,k*2+2,(l+r)/2+1,r);
		int z=min(x.second.first,y.second.second);
		return mp(x.first+y.first+z,mp(x.second.first+y.second.first-z,x.second.second+y.second.second-z));
	}
}seg;
char ss[1000005];
int main()
{
	scanf("%s",&ss);
	int n=strlen(ss);
	for(int i=0;i<n;i++)
	{
		seg.update(i,(ss[i]==')'));
	}
	seg.up();
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b; scanf("%d %d",&a,&b);
		a--; b--;
		printf("%d\n",seg.query(a,b,0,0,s-1).first*2);
	}
}