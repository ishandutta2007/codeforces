//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
	srand((unsigned int)time(NULL));
	int n,x;
	cin >> n >> x;
	bool used[4005]={};
	for(int i=0;i<x;i++)
	{
		int t; cin >> t;
		if(t==1)
		{
			int a,b;
			cin >> a >> b;
			used[a]=used[b]=true;
		}
		else
		{
			int a;
			cin >> a;
			used[a]=true;
		}
	}
	vector<int>cnt;
	int len=0;
	for(int i=1;i<n;i++)
	{
		if(used[i])
		{
			if(len)
			{
				cnt.pb(len);
				len=0;
			}
		}
		else
		{
			len++;
		}
	}
	if(len) cnt.pb(len);
	int ans1=0,ans2=0;
	for(int i=0;i<cnt.size();i++)
	{
		ans1+=(cnt[i]+1)/2;
		ans2+=cnt[i];
	}
	cout << ans1 << " " << ans2 << endl;
}