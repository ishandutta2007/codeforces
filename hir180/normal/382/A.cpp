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
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	string a,b;
	cin >> a >> b;
	int cur1,cur2;
	int add=b.size();
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='|')
		{
			cur1=i;
			cur2=a.size()-1-i;
			break;
		}
	}
	if((cur1+cur2+add)%2==1){ puts("Impossible"); return 0;}
	if((cur1+cur2+add)/2<max(cur1,cur2)){ puts("Impossible"); return 0;}
	int f=(cur1+cur2+add)/2;
	reverse(a.begin(),a.end());
	for(int i=0;i<f-cur1;i++)
	{
		a.pb(b[i]);
	}
	reverse(a.begin(),a.end());
	for(int i=0;i<f-cur2;i++)
	{
		a.pb(b[i+f-cur1]);
	}
	cout << a << endl;
}