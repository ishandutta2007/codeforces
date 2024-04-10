//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
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
int n,m,i,j,a,b;
int calc(int x,int y)
{
	int difx=abs(i-x);
	int dify=abs(j-y);
	if(difx%a!=0 || dify%b!=0) return INF;
	if((difx/a+dify/b)%2!=0) return INF;
	if(i!=x && j!=y) return max(difx/a,dify/b);
	if(i==x && j==y) return 0;
	if((i-a<1 && i+a>n)||(j-b<1 && j+b>m)) return INF;
	return max(difx/a,dify/b);
}
int main()
{
	scanf("%d %d %d %d %d %d"
	,&n,&m,&i,&j,&a,&b);
	int ret=INF;
	ret=min(ret,calc(1,1));
	ret=min(ret,calc(1,m));
	ret=min(ret,calc(n,1));
	ret=min(ret,calc(n,m));
	if(ret!=INF)
	{
		cout << ret << endl;
	}
	else
	{
		puts("Poor Inna and pony!");
	}
}