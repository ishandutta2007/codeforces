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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll f[100005];
ll rui[100005];
ll rr[100005];
ll x[100005];
int main()
{
	string s,t; cin >> s >> t;
	f[0] = 1;
	for(int i=1;i<=100000;i++) f[i]=(f[i-1]*10003ll)%mod;
	ll v = 0,cur = 0;
	for(int i=0;i<t.size();i++)
	{
		v = (v+(t[i]-'a')*f[t.size()-1-i])%mod;
	}
	for(int i=0;i<s.size();i++)
	{
		if(i>=t.size())
		{
			cur = (cur-f[t.size()-1]*(s[i-t.size()]-'a'));
			cur = (cur%mod+mod)%mod;
		}
		cur = (cur*10003ll)%mod;
		cur += (s[i]-'a');
		if(i >= t.size()-1)
		{
			if(cur == v) x[i+1] = i-t.size()+2;
		}
	}
	for(int i=1;i<=s.size();i++) x[i] = max(x[i],x[i-1]);
	for(int i=1;i<=s.size();i++)
	{
		if(x[i] == 0) continue;
		rui[i] = (rui[i-1]+rr[x[i]-1]+x[i])%mod;
		rr[i] = (rr[i-1]+rui[i])%mod;
	}
	cout << rui[s.size()] << endl;
}