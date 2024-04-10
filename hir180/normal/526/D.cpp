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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n,k;
string s;
ll hash[1000005][2];
ll f[1000005][2];
int rui[1000005];
bool check(int b,int c,int len)
{
	if(b+len-1 >= n || c+len-1 >= n) return false;
	ll ax = hash[b+len-1][0]-(b==0?0:hash[b-1][0]);
	ll ay = hash[c+len-1][0]-(c==0?0:hash[c-1][0]);
	if(ax<0) ax+=mod; if(ay<0) ay+=mod;
	if(ay == ax*f[c-b][0]%mod) return 1;
	else return 0;
}
int main()
{
	int q; cin >> n >> q;
	cin >> s;
	f[0][0] = 1;
	for(int i=1;i<=1000000;i++)
	{
		f[i][0] = f[i-1][0]*2LL%mod;
	}
	for(int i=0;i<n;i++)
	{
		if(i)
		{
			hash[i][0] = hash[i-1][0];
		}
		for(int j=0;j<1;j++)
		{
			hash[i][j] = (hash[i][j]+f[i][j]*(s[i]-'a'))%mod;
		}
	}
	int lb,ub;

	for(int i=1;i<=n/q;i++)
	{
		for(int j=0;j<q-1;j++)
		{
			if(!check(i*j,i*(j+1),i)) goto FAIL;
		}
		lb = 0;
		ub = i+1;
		//[lb,ub)
		while(ub-lb>1)
		{
			int mid = (lb+ub)/2;
			if(check(0,i*q,mid)) lb = mid;
			else ub = mid;
		}
		rui[i*q-1]++;
		rui[i*q+lb]--; FAIL:;
	}
	for(int i=0;i<n;i++)
	{
		rui[i] += rui[i-1];
		printf(rui[i]?"1":"0");
	}
	puts("");
}