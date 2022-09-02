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
#define INF 1000000001
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int f[1005][1005];
int n,m,k,p;
priority_queue<int>nn,mm;

int main()
{
	cin >> n >> m >> k >> p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cnt = 0;
		for(int j=1;j<=m;j++)
		{
			cnt += f[i][j];
		}
		nn.push(cnt);
	}
	for(int i=1;i<=m;i++)
	{
		int cnt = 0;
		for(int j=1;j<=n;j++)
		{
			cnt += f[j][i];
		}
		mm.push(cnt);
	}
	ll res = -1e18;
	vector<int>N,M;
	vector<ll>nsum,msum;
	while(N.size()<k)
	{
		int q = nn.top();
		N.pb(q);
		nn.pop();
		nn.push(q-p*m);
	}
	while(M.size()<k)
	{
		int q = mm.top();
		M.pb(q);
		mm.pop();
		mm.push(q-p*n);
	}
	reverse(N.begin(),N.end());
	reverse(M.begin(),M.end());
	//for(int i=0;i<N.size();i++) cout << N[i] << " ";
	//for(int i=0;i<M.size();i++) cout << M[i] << " ";
	for(int i=N.size()-1;i>=0;i--)
	{
		if(i==N.size()-1) nsum.pb((ll)N[i]);
		else nsum.pb(nsum.back()+(ll)N[i]);
	}
	for(int i=M.size()-1;i>=0;i--)
	{
		if(i==M.size()-1) msum.pb((ll)M[i]);
		else msum.pb(msum.back()+(ll)M[i]);
	}
	for(int i=0;i<=k;i++)
	{
		ll sum = -1LL * i * (k-i) * p;
		res = max(res,sum+(ll)(i==0?0:nsum[i-1])+(ll)(k==i?0:msum[k-i-1]));
	}
	cout << res << endl;
}