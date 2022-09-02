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
int p[10]={2,3,5,7,11,13,17,19,23,29},lim,k;
vector<int>generate(int x)
{
	vector<int>a;
	a.pb(1);
	int prev=-1;
	while(a.size()<=k && prev!=a.size())
	{
		int ss=a.size(); prev=ss;
		for(int k=0;k<ss;k++)
		{
			for(int j=0;j<=x;j++)
			{
				if(a[k]*p[j]<=lim) a.pb(a[k]*p[j]);
			}
		}
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
	}
	if(a.size()>k) return a;
	else{ vector<int>res(0); return res;}
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&k);
	lim=k*k*2;
	vector<int>cur;
	for(int i=0;i<10;i++)
	{
		cur=generate(i);
		if(cur.size()>k) break;
	}
	for(int i=1;i<=k;i++) printf("%d ",cur[i]);
	puts("");
}