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

int main()
{
	int n;
	cin >> n;
	vector<int>vec;
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		vec.pb(x);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int res = 0;
	
	for(int i=0;i<vec.size();i++)
	{
		for(int j=2;;j++)
		{
			int s = lower_bound(vec.begin(),vec.end(),vec[i]*j)-vec.begin();
			if(s == 0) continue;
			res = max(res,vec[s-1] - vec[i]*(j-1));
			if(s == vec.size()) break;
		}
	}
	
	cout << res << endl;
}