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


int t[2005];
int h[2005];
int m[2005];
int a[2005];
bool used[2005];
int n,x;
bool cmp(int a,int b)
{
	return h[a] < h[b];
}

int main()
{
	srand((unsigned int)time(NULL));
	cin >> n >> x;
	//priority_queue<int> que[2];
	for(int i=0;i<n;i++)
	{
		cin >> t[i] >> h[i] >> m[i];
		a[i] = i;
	}
	sort(a,a+n,cmp);
	int res = 0;
	priority_queue<int>que[2];
	//begin with 0
	int cur = 0,jump = x,nxt = 0,tot = 0;
	memset(used,0,sizeof(used));
	while(nxt != n && h[a[nxt]] <= jump)
	{
		que[t[a[nxt]]].push(m[a[nxt]]);
		nxt++;
	}
	while(1)
	{
		if(que[cur].empty()) break;
		int q = que[cur].top(); que[cur].pop();
		jump += q;
		cur = 1-cur;
		tot ++;
		while(nxt != n && h[a[nxt]] <= jump)
		{
			que[t[a[nxt]]].push(m[a[nxt]]);
			nxt++;
		}
	}
	res = max(res,tot);
	
	//begin with 1
	while(!que[0].empty()) que[0].pop();
	while(!que[1].empty()) que[1].pop();
	cur = 1,jump = x,nxt = 0,tot = 0;
	memset(used,0,sizeof(used));
	while(nxt != n && h[a[nxt]] <= jump)
	{
		que[t[a[nxt]]].push(m[a[nxt]]);
		nxt++;
	}
	while(1)
	{
		if(que[cur].empty()) break;
		int q = que[cur].top(); que[cur].pop();
		jump += q;
		cur = 1-cur;
		tot ++;
		while(nxt != n && h[a[nxt]] <= jump)
		{
			que[t[a[nxt]]].push(m[a[nxt]]);
			nxt++;
		}
	}
	res = max(res,tot);
	
	cout << res << endl;
}