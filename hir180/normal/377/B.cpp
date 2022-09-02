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
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;

#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
P bug[100005];
ll abi[100005];
ll mon[100005];
P1 student[100005];
int ret[100005];
int main()
{
	int n,m;
	ll s;
	scanf("%d %d %lld",&n,&m,&s);
	ll bugmax=-1LL;
	ll abimax=-1LL;
	for(int i=0;i<m;i++)
	{
		ll bugg;
		scanf("%lld",&bugg);
		bug[i]=mp(bugg,i);
		bugmax=max(bugmax,bug[i].first);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&abi[i]);
		abimax=max(abimax,abi[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&mon[i]);
		student[i-1]=mp(mp(abi[i],mon[i]),i);
	}
	if(bugmax>abimax)
	{
		puts("NO"); return 0;
	}
	sort(bug,bug+m,greater<P>());
	sort(student,student+n,greater<P1>());
//for(int i=0;i<m;i++) cout << bug[i].first << " " << bug[i].second << endl;
//for(int i=0;i<n;i++) cout << student[i].first.first << " " << student[i].first.second << " " << student[i].second << endl;
	int lb=0; int ub=100005;
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		int cur=0;
		int bugn=0;
		priority_queue<P1,vector<P1>,greater<P1> >que;
		while(!que.empty()) que.pop();
		ll val=0LL;
		while(bugn<m)
		{
			while(cur!=n && student[cur].first.first>=bug[bugn].first)
			{
				que.push(mp(mp(student[cur].first.second,student[cur].first.first),student[cur].second));
				cur++; //cout << cur << " " << mid  << endl;
			}
			if(que.empty()){ lb=mid; goto end;}
			val+=que.top().first.first; que.pop();
			bugn+=mid; //if(mid==2) cout << bugn << endl;
		}
		if(val<=s) ub=mid;
		else lb=mid;
end:;
	}
	if(ub>=100001)
	{
		puts("NO"); return 0;
	}
	puts("YES");
		int mid=ub;
		int cur=0;
		int bugn=0;
		priority_queue<P1,vector<P1>,greater<P1> >que;
		while(!que.empty()) que.pop();
		ll val=0LL;
		while(bugn<m)
		{
			while(cur!=n && student[cur].first.first>=bug[bugn].first)
			{
				que.push(mp(mp(student[cur].first.second,student[cur].first.first),student[cur].second));
				cur++;
			}
			for(int i=bugn;i<min(bugn+mid,m);i++)
			{
				ret[bug[i].second]=que.top().second;
			}
			que.pop();
			bugn+=mid;
		}
		for(int i=0;i<m;i++)
		{
			printf("%d%c",ret[i],(i==m-1)?'\n':' ');
		}
}