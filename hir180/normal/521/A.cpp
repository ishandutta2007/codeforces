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
int main()
{
	int n;string s;
	cin >> n >> s;
	map<char,int>ma;
	for(int i=0;i<s.size();i++)
	{
		ma[s[i]]++;
	}
	int a = max(max(ma['A'],ma['C']),max(ma['G'],ma['T']));
	int cnt = 0;
	if(ma['A'] == a) cnt++;
	if(ma['C'] == a) cnt++;
	if(ma['G'] == a) cnt++;
	if(ma['T'] == a) cnt++;
	ll res = 1;
	for(int i=0;i<n;i++)
	{
		res = res*1LL*cnt;
		res %= mod;
	}
	cout << res << endl;
}