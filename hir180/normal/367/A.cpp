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
int x[100005],y[100005],z[100005];
int main()
{
	srand((unsigned int)time(NULL));
	string s; cin >> s;
	for(int i=0;i<s.size();i++)
	{
		x[i+1]=x[i]+(s[i]=='x');
		y[i+1]=y[i]+(s[i]=='y');
		z[i+1]=z[i]+(s[i]=='z');
	}
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r; scanf("%d%d",&l,&r);
		int a=x[r]-x[l-1];
		int b=y[r]-y[l-1];
		int c=z[r]-z[l-1];
		if(r-l+1<=2 || min(a,min(b,c))+1>= max(a,max(b,c))) puts("YES");
		else puts("NO");
	}
}