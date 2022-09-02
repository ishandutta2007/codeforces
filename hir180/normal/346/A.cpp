//E? Nanndatte?
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
long long gcd(long long a,long long b)
{
	if(a<b) swap(a,b);
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}

int main(){
	int n;
	cin >> n;
	long long cur;
	long long upper=-1LL;
	for(int i=0;i<n;i++)
	{
		long long val;
		cin >> val;

		upper=max(upper,val);

		if(!i)
		{
			cur=val;
		}
		else

		{
			cur=gcd(cur,val);
		}
	}

	long long d=upper/cur;

	puts((d-n)%2==0?"Bob":"Alice");
}