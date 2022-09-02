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
int main()
{
	srand((unsigned int)time(NULL));
	string s; cin >> s;
	s.pb(s[0]);
	s.pb(s[1]);
	s.pb(s[2]);
	int ret=0;
	for(int i=0;i<s.size()-3;i++)
	{
		if(s[i]!=s[i+1] && s[i]!=s[i+2]) ret++;
	}
	for(int i=0;i<s.size()-3;i++)
	{
		if(s[i]!=s[i+1] && s[i]==s[i+2] && s[i+3]!=s[i])
		{
			 ret++; i++;
		}
	}
	cout << ret << endl;
}