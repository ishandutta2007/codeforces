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
int num[105];
int b,d; char a[105],c[105];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d%d%s%s",&b,&d,&a,&c);
	int al=strlen(a);
	int cl=strlen(c);
	for(int i=0;i<cl;i++)
	{
		for(int j=0;j<al;j++)
		{
			if(a[j]==c[(i+num[i])%cl])
			{
				num[i]++;
			}
		}
		if(num[i]==0)
		{
			puts("0");
			return 0;
		}
	}
	int cur=0;
	ll ret=0;
	for(int i=0;i<b;i++)
	{
		ret+=num[cur];
		cur=(cur+num[cur])%cl;
	}
	printf("%lld\n",ret/(d*cl));
}