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
	int gen=INF;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x; cin >> x;
		gen=min(gen,x);
	}
	int m;
	vector<int>vec;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int a; cin >> a;
		vec.pb(a);
	}
	sort(vec.begin(),vec.end(),greater<int>());
	int tot=0;
	for(int i=0;i<vec.size();i+=gen+2)
	{
		for(int j=i;j<i+gen;j++)
		{
			if(j<m) tot+=vec[j];
		}
	}
	cout << tot << endl;
}