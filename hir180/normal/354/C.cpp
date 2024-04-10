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
int rui[1000005];
int cnt[1000005];
int n,k;
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&k);
	for(int i=0,x;i<n;i++) scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=1000000;i++) rui[i]=rui[i-1]+cnt[i];
	int ret=1;
	for(int i=2;i<=1000000;i++)
	{
		int res=0;
		for(int j=1;i*j<=1000000;j++)
		{
			res+=rui[min(1000000,min(i*(j+1)-1,i*j+k))]-rui[i*j-1];
		}
		if(res==n) ret=i;
	}
	printf("%d\n",ret);
}