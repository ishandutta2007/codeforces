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
int val[105]={};
int main()
{
	int n,m;
	s(n);  s(m);
	for(int i=0;i<m;i++)
	{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			val[a]+=c;
			val[b]-=c;
	}
	for(int i=1;i<=n;i++) val[i]=abs(val[i]);
	int ret=0;
	for(int i=1;i<=n;i++) ret+=val[i];
	printf("%d\n",ret/2);
}