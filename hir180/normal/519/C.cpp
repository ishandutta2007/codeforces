#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
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
	int a,b;
	cin >> a >> b;
	if(a*2 <= b)
	{
		cout << a << endl;
	}
	else if(b*2 <= a)
	{
		cout << b << endl;
	}
	else
	{
		cout << (a+b)/3 << endl;
	}
}