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
	int a,b;
	int c=0,d=0,e=0;
	cin >> a >> b;
	for(int i=1;i<=6;i++)
	{
			if(abs(i-a)<abs(i-b)) c++;
			if(abs(i-a)==abs(i-b)) d++;
			if(abs(i-a)>abs(i-b)) e++;
	}

	cout << c << " " <<  d  << " " << e << endl;
}