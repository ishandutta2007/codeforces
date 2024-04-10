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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int s,a[3];
	cin >> s >> a[0] >> a[1] >> a[2];
	if(count(a,a+3,0)==3) {puts("0 0 0");return 0;}
	int sum=a[0]+a[1]+a[2];
	printf("%.10f %.10f %.10f\n",((double)s*a[0]/(double)sum),((double)s*a[1]/(double)sum),((double)s*a[2]/(double)sum));
}