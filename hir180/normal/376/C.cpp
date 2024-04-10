//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int v[10]={},cur=0;
	string s; cin >> s;
	for(int i=0;i<s.size();i++) v[s[i]-'0']++;
	v[1]--;v[6]--;v[8]--;v[9]--;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=v[i];j++)
		{
			cur=(cur*10+i)%7;
			printf("%d",i);
		}
	}
	cur=(cur*10000)%7;
	int vv[4]={1,6,8,9};
	do
	{
		int d=0;
		for(int i=0;i<4;i++)
		{
			d=(d*10+vv[i]);
		}
		d%=7;
		if((cur+d)%7==0)
		{
			for(int i=0;i<4;i++) printf("%d",vv[i]);
			for(int i=0;i<v[0];i++) printf("0");
			return 0;
		}
	}while(next_permutation(vv,vv+4));
}