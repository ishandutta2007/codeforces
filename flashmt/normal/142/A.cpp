#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1LL << 60
#define maxN 1
using namespace std;

int n;
long long Min=oo,Max=-oo;

void att(int a)
{
	int N=n/a;
	for (int b=1;b*b<=N;b++)
		if (N%b==0)
		{
			int c=N/b;
			long long s=1LL*(b+2)*(c+2)*(a+1)-1LL*a*b*c;
			Min=min(s,Min);
			Max=max(s,Max);
		}
}

int main()
{
	cin >> n;
	for (int a=1;a*a<=n;a++)
		if (n%a==0) att(a), att(n/a);	
	cout << Min << ' ' << Max << endl;		
}