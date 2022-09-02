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
	int t; cin >> t;
	while(t--)
	{
		int n,p; scanf("%d %d",&n,&p);
		bool used[50][50]={};
		for(int i=1;i<=n;i++)
		{
			if(i<n) { printf("%d %d\n",i,i+1); used[i][i+1]=true;}
			else { printf("%d %d\n",1,n); used[1][n]=true;}
		}
		for(int i=1;i<=n;i++)
		{
			if(i<n-1) { printf("%d %d\n",i,i+2); used[i][i+2]=true;}
			else if(i==n-1) { printf("%d %d\n",1,n-1); used[1][n-1]=true;}
			else { printf("%d %d\n",2,n); used[2][n]=true;}
		}
		int rem=p;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(used[i][j]) continue;
				if(!rem) goto out;
				printf("%d %d\n",i,j); rem--;
			}
		}out:;
	}
}