//Bokann ga bokka--nn!!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int val[500005];
int used[500005]={};
int ans=INF;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	sort(val,val+n);
	int lb=0;
	int ub=n/2+1;
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		if(mid-1>=n-mid) goto out;
		for(int i=0;i<mid;i++)
		{
			if(val[i]*2>val[i+n-mid])
			{
				goto out;
			}
		}
		lb=mid;
		continue;
out:;
		ub=mid;
	}
	for(int mid=min(n/2,ub+3);mid>=max(0,lb-3);mid--)
	{
		for(int i=0;i<mid;i++)
		{
			if(val[i]*2>val[i+n-mid])
			{
				goto outw;
			}
		}
		cout << n-mid << endl;
		return 0;
outw:;
	}
}