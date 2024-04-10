//IOI2014
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
#define geta 100000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int num[205],n,k;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	int res=-INF;
	multiset<int,greater<int> >se;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++) se.insert(num[j]);
		
		multiset<int>se2;
		int sum=0;
		
		for(int j=i;j<=n;j++)
		{
			se2.insert(num[j]);
			se.erase(se.find(num[j]));
			sum+=num[j];
			int dif=0,pl=0;
			multiset<int,greater<int> >::iterator it=se.begin();
			multiset<int>::iterator it2=se2.begin();
			
			while(it != se.end() && it2 != se2.end () && dif < k && *it > *it2)
			{
				pl += (*it - *it2);
				it++; it2++; dif++;
			}
			res = max(res,sum+pl);
		}
		se.insert(num[i]);
	}
	cout << res << endl;
}