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
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
#define s 524288
int a[100005],b[100005],c[100005];
class segtree
{
	public:
	int seg[s*2];
	int lazy[s*2];
	void init()
	{
		for(int i=0;i<s*2;i++)
		{
			seg[i]=0;
		}
	}
	void lazy_evaluate(int x)
	{
		if(x*2+2>=s*2) return ;
		lazy[x*2+1]+=lazy[x];
		lazy[x*2+2]+=lazy[x];
		seg[x*2+1]+=lazy[x];
		seg[x*2+2]+=lazy[x];
		lazy[x]=0;
	}
	int update(int a,int b,int k,int lb,int ub,int val)
	{
		pair<int,int>p;
		p.first=-INF,p.second=-INF;
		if(ub<a  || b<lb) return seg[k];
		if(a<=lb && ub<=b)
		{
			lazy[k]+=val;
			seg[k]+=val;
			return seg[k];
		}
		if(lazy[k]) lazy_evaluate(k);
		int p1=update(a,b,k*2+1,lb,(lb+ub)/2,val);
		int p2=update(a,b,k*2+2,(lb+ub)/2+1,ub,val);
		return seg[k]=max(p1,p2);
	}
	int query(){ return seg[0];}
}seg;
int main()
{
	int n;
	vector<P1>p;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		p.pb(mp(a[i],mp(b[i],c[i])));
	}
	sort(p.begin(),p.end());
	seg.init();
	int ret=-1;
	int lb,ub;
	priority_queue<P,vector<P>,greater<P> >que;
	for(int i=0;i<n;i++)
	{
		while(!que.empty() && p[i].first>que.top().first)
		{
			seg.update(p[que.top().second].second.first,p[que.top().second].second.second,0,0,s-1,-1);
			que.pop();
		}
		que.push(mp(p[i].second.first,i));
		seg.update(p[i].second.first,p[i].second.second,0,0,s-1,1);
		int pp=seg.query(); //cout << pp << endl;
		if(pp>ret)
		{
			ret=pp;
			lb=p[i].first;
		}
	}
	printf("%d\n",ret);
	priority_queue<int,vector<int>,greater<int> >que2;
	int next;
	vector<P>in;
	for(int i=0;i<n;i++)
	{
		if(p[i].second.first>=lb && p[i].first<=lb)
		{
			in.pb(mp(p[i].second.first,i));
		}
	}
	sort(in.begin(),in.end());
	next=0;
	for(int j=lb;;j++)
	{
		while(!que2.empty() && que2.top()<j) que2.pop();
		while(next!=in.size() && in[next].first<=j) { que2.push(p[in[next].second].second.second); next++;}
		if(que2.size()==ret){ ub=j; break;}
	}
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=lb && ub<=c[i] && lb<=b[i] && b[i]<=ub)
		{
			x++;
			printf("%d%c",i+1,x==ret?'\n':' ');
		}
	}
}