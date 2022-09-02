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
#define s (1<<18)
int n;
struct gripper
{
	ll weight,dist,power,rng;
	gripper(){}
	gripper(ll a,ll b,ll c,ll d):weight(a),dist(b),power(c),rng(d){}
	bool operator < (const gripper& gr) const
	{
		return dist<gr.dist;
	}
};
vector<gripper>vec;
class segtree
{
	public:
	int id[s*2];
	void init(){ fill(id,id+s*2,n); }
	void update(int pos)
	{
		id[pos+s-1]=pos;
		int cur=pos+s-1;
		while(cur>0)
		{
			cur=(cur-1)/2;
			if(vec[id[cur*2+1]].weight<vec[id[cur*2+2]].weight)
			{
				id[cur]=id[cur*2+1];
			}
			else
			{
				id[cur]=id[cur*2+2];
			}
		}
	}
	void del(int pos)
	{
		id[pos+s-1]=n;
		int cur=pos+s-1;
		while(cur>0)
		{
			cur=(cur-1)/2;
			if(vec[id[cur*2+1]].weight<vec[id[cur*2+2]].weight)
			{
				id[cur]=id[cur*2+1];
			}
			else
			{
				id[cur]=id[cur*2+2];
			}
		}
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(r<a || b<l) return n;
		if(a<=l && r<=b) return id[k];
		int lb=get(a,b,k*2+1,l,(l+r)/2);
		int ub=get(a,b,k*2+2,(l+r)/2+1,r);
		if(vec[lb].weight<vec[ub].weight) return lb;
		else return ub;
	}
}seg;
int main()
{
	srand((unsigned int)time(NULL));
	ll sx,sy,power,rng;
	scanf("%lld %lld %lld %lld",&sx,&sy,&power,&rng);
	scanf("%d",&n);
	vector<ll>lis;
	for(int i=0;i<n;i++)
	{
		ll x,y,w,p,r;
		scanf("%lld %lld %lld %lld %lld",&x,&y,&w,&p,&r);
		ll dist=(sx-x)*(sx-x)+(sy-y)*(sy-y);
		ll weight=w;
		ll power2=p;
		ll rng2=r*r;
		vec.pb(gripper(weight,dist,power2,rng2));
		lis.pb(dist);
	}
	sort(vec.begin(),vec.end());sort(lis.begin(),lis.end());
	vec[n].weight=1e18; seg.init();
	for(int i=0;i<n;i++) seg.update(i);
	queue<gripper>cur;
	cur.push(gripper(0,0,power,rng*rng));
	int tot=0;
	while(!cur.empty())
	{
		gripper gr=cur.front(); cur.pop();
		int id=upper_bound(lis.begin(),lis.end(),gr.rng)-lis.begin();
		id--;
		while(1)
		{
			int nxt=seg.get(0,id,0,0,s-1);
			if(gr.power<vec[nxt].weight) break;
			cur.push(vec[nxt]); tot++;
			seg.del(nxt);
		}
	}
	printf("%d\n",tot);
}