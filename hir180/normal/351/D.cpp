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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int n, a[100005], ret[100005];
int q;
int rng=350;

struct Query 
{
	int l,r,id;
	void read(int id)
	{
		this->id = id;
		scanf("%d%d", &l, &r);
		--l, --r;
	}
	bool operator<(const Query& a) const
	{
		if (l/rng != a.l/rng)
			return l/rng<a.l/rng;
		return r<a.r;
	}
};

Query qs[100005];

deque<int> by[100005];
int cntw[100005], cnt[100005], tot;

int l,r,ans;

void dec2(int at)
{
	if (--cntw[at]==0)
	{
		if (++tot==1) --ans;
	}
}

void add2(int at)
{
	if (++cntw[at] == 1)
	{
		if (--tot==0) ++ans;
	}
}

void dec(int at)
{
	if (--cnt[at] == 0)
	{
		--ans;
		if (--tot == 0) ++ans;
	}
}

void add(int at)
{
	if (++cnt[at] == 1)
	{
		++ans;
		if (++tot == 1) --ans;
	}
}

void decLeft()
{
	int x=a[--l],at=l;
	deque<int>&v=by[x];
	v.push_front(at);
	add(x);
	if (v.size()>=3&&v[1]-v[0]!=v[2]-v[1]) add2(x);
}

void incLeft()
{
	int x=a[l++];
	deque<int>&v=by[x];
	dec(x);
	if (v.size()>=3&&v[1]-v[0]!=v[2]-v[1]) dec2(x);
	v.pop_front();
}

void incRight()
{
	int x=a[++r],at = r;
	deque<int>&v=by[x];
	add(x);
	v.push_back(at);
	int m=v.size();
	if (v.size()>=3&&v[m - 1]-v[m - 2]!=v[m - 2]-v[m - 3]) add2(x);
}

void decRight()
{
	int x=a[r--];
	deque<int>&v=by[x];
	int m=v.size();
	dec(x);
	if (v.size()>=3&&v[m - 1]-v[m - 2]!=v[m - 2]-v[m - 3]) dec2(x);
	v.pop_back();
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	scanf("%d",&q);
	for (int i=0;i<q;++i) qs[i].read(i);
	sort(qs,qs+q);
	l=0,r=-1;
	for (int i=0;i<q;++i)
	{
		Query &q=qs[i];
		while (r<q.r) incRight();
		while (l>q.l) decLeft();
		while (r>q.r) decRight();
		while (l<q.l) incLeft();
		ret[q.id]=ans;
	}
	for (int i=0;i<q;++i)
	{
		printf("%d\n",ret[i]+1);
	}
}