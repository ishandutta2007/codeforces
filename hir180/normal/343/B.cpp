//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
	string str;
	cin >> str;
	if(str.size()%2==1)
	{
		cout << "No" << endl;
		return 0;
	}
	stack<char>sta;
	for(int i=0;i<str.size();i++)
	{
		if(!sta.empty() && sta.top()==str[i]) sta.pop();
		else sta.push(str[i]);
	}
	puts(sta.empty()?"Yes":"No");
}