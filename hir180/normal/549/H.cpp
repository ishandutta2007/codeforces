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
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int main()
{
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	double lb = 0,ub = 2000000000,mid;
	for(int i=0;i<10000;i++)
	{
		mid = (lb+ub)/2;
		vector<double>A,B,C,D;
		A.pb(a-mid);
		A.pb(a+mid);
		if(a-mid <= 0 && 0<=a+mid) A.pb(0);
		B.pb(b-mid);
		B.pb(b+mid);
		if(b-mid <= 0 && 0<=b+mid) B.pb(0);
		C.pb(c-mid);
		C.pb(c+mid);
		if(c-mid <= 0 && 0<=c+mid) C.pb(0);
		D.pb(d-mid);
		D.pb(d+mid);
		if(d-mid <= 0 && 0<=d+mid) D.pb(0);
		double minv=1e30,maxv=-1e30;
		for(int j=0;j<A.size();j++)
		{
			for(int k=0;k<D.size();k++)
			{
				minv = min(minv,A[j]*D[k]);
				maxv = max(maxv,A[j]*D[k]);
			}
		}
		double minv2=1e30,maxv2=-1e30;
		for(int j=0;j<B.size();j++)
		{
			for(int k=0;k<C.size();k++)
			{
				minv2 = min(minv2,B[j]*C[k]);
				maxv2 = max(maxv2,B[j]*C[k]);
			}
		}
		if(maxv < minv2 || maxv2 < minv) lb = mid;
		else ub = mid;
	}
	printf("%.12f\n",mid);
}