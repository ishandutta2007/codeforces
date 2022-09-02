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
int t[6][3];
ll sq[1000005];
int main()
{
	ll h[8][3];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin >> h[i][j];
		}
	}
	for(ll i=1;i<=1000000;i++) sq[i] = i*i;
	int cnt = 0;
	for(int a=0;a<3;a++)
	{
		for(int b=0;b<3;b++)
		{
			for(int c=0;c<3;c++)
			{
				if(a==b || a==c || b==c) continue;
				t[cnt][0] = a;
				t[cnt][1] = b;
				t[cnt][2] = c;
				cnt++;
			}
		}
	}
	for(int mask=0;mask<6*6*6*6*6*6*6*6;mask++)
	{
		int v[8];
		int cpy = mask;
		for(int i=0;i<8;i++)
		{
			v[i] = cpy%6;
			cpy /= 6;
		}
		ll za[8][3];
		for(int i=0;i<8;i++)
		{
			za[i][t[v[i]][0]] = h[i][0];
			za[i][t[v[i]][1]] = h[i][1];
			za[i][t[v[i]][2]] = h[i][2];
		}
		ll minv = 1e18;
		ll dist[8][8]; vector<int>hoge[8][4];
		for(int i=0;i<8;i++)
		{
			for(int j=i+1;j<8;j++)
			{
				ll x = 0;
				for(int a=0;a<3;a++) x += (za[i][a]-za[j][a])*(za[i][a]-za[j][a]);
				minv = min(minv,x);
				if(minv == 0) goto fail;
				if(x%minv != 0) goto fail;
				if(x/minv > 3) goto fail;
				dist[i][j] = dist[j][i] = x;
			}
		}
		for(int i=0;i<8;i++)
		{
			int ch[4]={};
			for(int j=0;j<8;j++)
			{
				if(i == j) continue;
				if(dist[i][j] != minv && dist[i][j] != minv*2LL && dist[i][j] != minv*3LL) goto fail;
				ll a = (dist[i][j]/minv);
				ch[a]++; hoge[i][a].pb(j);
			}
			if(ch[1] != 3 || ch[2] != 3 || ch[3] != 1) goto fail;
		}
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<hoge[i][2].size();j++)
			{
				if(dist[hoge[i][2][j]][hoge[i][1][0]] == dist[hoge[i][2][j]][hoge[i][1][1]] && dist[hoge[i][2][j]][hoge[i][1][0]] == minv){}
				else if(dist[hoge[i][2][j]][hoge[i][1][0]] == dist[hoge[i][2][j]][hoge[i][1][2]] && dist[hoge[i][2][j]][hoge[i][1][0]] == minv){}
				else if(dist[hoge[i][2][j]][hoge[i][1][1]] == dist[hoge[i][2][j]][hoge[i][1][2]] && dist[hoge[i][2][j]][hoge[i][1][1]] == minv){}
				else goto fail;
			}
		}
		puts("YES");
		for(int i=0;i<8;i++)
		{
			printf("%lld %lld %lld\n",za[i][0],za[i][1],za[i][2]);
		}
		return 0; fail:;
	}
	puts("NO");
}