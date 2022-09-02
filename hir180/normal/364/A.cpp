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
int rui[4005];
int v[40005]={};
int main()
{
	srand((unsigned int)time(NULL));
	int a;
	char str[4005];
	scanf("%d%s",&a,&str);
	int n=strlen(str);
	for(int i=1;i<=n;i++)
	{
		rui[i]=rui[i-1]+str[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=rui[j]-rui[i-1];
			v[x]++;
		}
	}
	ll ret=0;
	if(!a){ for(int i=0;i<=40000;i++) ret+=v[i]; ret*=v[0]; return !printf("%lld\n",ret*2-1LL*v[0]*v[0]);}
	for(int i=1;i*i<=a;i++)
	{
		if(a%i!=0) continue;
		if(a/i>40000) continue;
		if(i!=a/i) ret+=2LL*v[i]*v[a/i];
		else ret+=1LL*v[i]*v[a/i];
	}
	printf("%lld\n",ret);
}