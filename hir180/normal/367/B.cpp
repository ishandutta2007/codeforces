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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)

int n,m,p;
int a[200005],b[200005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	vector<int>ret;
	for(int i=1;i<=p;i++)
	{
		if(1LL*i+1LL*(m-1)*p>1LL*n) break; map<int,int>ma;
		for(int j=1;j<=m;j++)
		{
			ma[b[j]]++;
		}
		int rem=m;
		for(int j=i;j<=i+(m-1)*p;j+=p)
		{
			ma[a[j]]--;
			if(ma[a[j]]>=0) rem--;
			else rem++;
		}
		if(!rem) ret.pb(i);
		for(int en=i+m*p;en<=n;en+=p)
		{
			ma[a[en]]--;
			if(ma[a[en]]>=0) rem--;
			else rem++;
			ma[a[en-m*p]]++;
			if(ma[a[en-m*p]]>0) rem++;
			else rem--;
			if(!rem) ret.pb(en-(m-1)*p);
		}
	}
	printf("%d\n",ret.size()); sort(ret.begin(),ret.end());
	for(int i=0;i<ret.size();i++) printf("%d ",ret[i]);
	if(ret.size()) puts("");
}