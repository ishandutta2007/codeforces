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
	string s;
	cin >> s;
	int id;
	for(int i=0;i<s.size();i++)
	{
			if(s[i]=='^') id=i;
	}
	ll val=0;
	for(int i=0;i<s.size();i++)
	{
			if(1<=s[i]-'0' && s[i]-'0'<=9)
			{
				val+=((id-i)*(s[i]-'0')*1ll);
			}
	}
	if(val>0ll) puts("left");
	else if(val<0ll) puts("right");
	else puts("balance");
}