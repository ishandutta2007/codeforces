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
int main()
{
	int n;
	int v[305];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	for(int i=0;i<n;i++)
	{
		while(v[i])
		{
			printf("P");
			v[i]--;
			if(!v[i]) break;
			if(i-1>=0) printf("LR");
			else printf("RL");
		}
		if(i!=n-1) printf("R");
	}
puts("");
}