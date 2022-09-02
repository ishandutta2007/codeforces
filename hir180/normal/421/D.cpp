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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n,m;
int num[300005];
map<P,int>ma;
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		num[a]++;
		num[b]++;
		if(a>b) swap(a,b);
		ma[mp(a,b)]++;
	}
	vector<int>zip;
	for(int i=1;i<=n;i++) zip.pb(num[i]);
	sort(zip.begin(),zip.end());
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		int x = lower_bound(zip.begin(),zip.end(),m-num[i])-zip.begin();
		//x~zip.size()-1
		tot+=zip.size()-x;
	}
	for(int i=1;i<=n;i++) if(num[i]*2 >= m) tot--;
	tot/=2;
//cout << tot << endl;
	for(map<P,int>::iterator it=ma.begin();it!=ma.end();it++)
	{
		P p=it->fi;
		int oc=it->sc;
		int tot2=num[p.fi]+num[p.sc]-oc;
		if(tot2<m && num[p.fi]+num[p.sc]>=m) tot--;
	}
	cout << tot << endl;
}