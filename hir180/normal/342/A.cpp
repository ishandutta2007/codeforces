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
int main(){
	int n;
	cin >> n;
	int val[10]={};
	for(int i=0;i<n;i++)
	{
		int d;
		cin >> d;
		val[d]++;
		if(d==5 || d==7)
		{
			puts("-1");
			return 0;
		}
	}
	if(val[1]!=n/3)
	{
		puts("-1");
		return 0;
	}
	if(val[2]+val[3]!=val[4]+val[6])
	{
		puts("-1");
		return 0;
	}
	int a=val[4];
	int b=val[2]-val[4];
	int c=val[3];
	if(a<0 || b<0 || c<0)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<a;i++) printf("1 2 4\n");
	for(int i=0;i<b;i++) printf("1 2 6\n");
	for(int i=0;i<c;i++) printf("1 3 6\n");
}