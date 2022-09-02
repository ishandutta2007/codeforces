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
#define INF 1000000005
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int main()
{
	int n,k; cin >> n >> k;
	vector<int>res;
	res.pb(1);
	for(int i=k;i>=1;i--)
	{
		if(i%2 == k%2) res.pb(res.back()+i);
		else res.pb(res.back()-i);
	}
	for(int i=k+2;i<=n;i++)
	{
		res.pb(i);
	}
	for(int i=0;i<n;i++) printf("%d%c",res[i],i==n-1?'\n':' ');
}