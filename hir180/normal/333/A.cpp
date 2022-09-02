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
int n;
int main(){
	long long x;
	cin >> x;
	if(x==1)
	{
		puts("1");
	}
	else if(x==2)
	{
		puts("1");
	}
	else if(x==3)
	{
		puts("1");
	}
	else
	{
		long long mul=1;
		while(x%mul==0)
		{
			mul*=3LL;
		}
		cout << (x+mul-1)/mul << endl;
	}

}