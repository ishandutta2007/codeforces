#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <functional>
#include <queue>
 
using namespace std;
 
typedef pair<int,int> P;
typedef pair<int,P> P1;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 100000000

int main()
{
	int n;
	cin >> n;
	multiset<int>se;
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		se.insert(x);
	}
	multiset<int>se2;
	for(int i=0;i<n-1;i++)
	{
		int x; scanf("%d",&x);
		se2.insert(x);
		se.erase(se.find(x));
	}
	cout << *se.begin() << endl;
	for(int i=0;i<n-2;i++)
	{
		int x; scanf("%d",&x);
		se2.erase(se2.find(x));
	}
	cout << *se2.begin() << endl;
}