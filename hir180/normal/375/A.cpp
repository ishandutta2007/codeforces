//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
int main()
{
	srand((unsigned int)time(NULL));
	string s;
	cin >> s;
	int v[10]={};
	for(int i=0;i<s.size();i++) v[s[i]-'0']++;
	ll cur=0;
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<v[i]-(i==1 || i==6 || i==8 || i==9);j++)
		{
			printf("%d",i);
			cur=(cur*10+i)%7;
		}
	}
	int d[4]={1,6,8,9};
	do
	{
		if((1000*d[0]+100*d[1]+10*d[2]+d[3]+cur*10000)%7==0)
		{
			for(int i=0;i<4;i++) printf("%d",d[i]); for(int j=0;j<v[0];j++) printf("0"); puts(""); return 0;
		}
	}while(next_permutation(d,d+4));
}