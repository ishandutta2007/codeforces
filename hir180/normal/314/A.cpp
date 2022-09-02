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
int main(){
	long long n,k;
	vector<long long>num;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		long long g;
		cin >> g;
		num.pb(g);
	}
	vector<long long>ans;
	long long cur=n;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		if(i==0 || i==n-1)
		{
			ans.pb(i+1);
		}
		else
		{
			if(sum-(cur-ans.size()-1)*num[i]*(ans.size())>=k)
			{
				sum+=num[i]*(ans.size())*1LL;
				ans.pb(i+1);
			}
			else
			{
				cur--;
			}
		}
	}
	int q=0;
	for(int i=1;i<=n;i++)
	{
		if(ans[q]==i)
		{
			q++;
		}
		else
		{
			printf("%d\n",i);
		}
	}
}