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
	int n;
	int a[55];
	int p;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cin >> p;
	double ret=0.0;
	for(int i=1;i<=n;i++)
	{
		ll dp[2505][55]={};
		dp[0][0]=1LL;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			for(int k=2500;k>=0;k--)
			{
				for(int b=j-1;b>=0;b--)
				{
					if(!dp[k][b]) continue;
					dp[k+a[j]][b+1]+=dp[k][b];
				}
			}
		}
		for(int j=0;j<=p-a[i];j++)
		{
			for(int k=0;k<n;k++)
			{
				if(!dp[j][k]) continue;
				//dp[j][k]*k!*(n-1-k)!/n!
				double x=(double)dp[j][k];
				double cur=1.0;
				for(int s=1;s<=k;s++)
				{
					x*=s;
					while(x>1e10 && cur<=n)
					{
						x/=cur;
						cur+=1.0;
					}
				}
				for(int s=1;s<=n-1-k;s++)
				{
					x*=s;
					while(x>1e10 && cur<=n)
					{
						x/=cur;
						cur+=1.0;
					}
				}
				while(cur<=n)
				{
						x/=cur;
						cur+=1.0;
				}
				ret+=x;
			}
		}
	}
	cout << ret << endl;
}