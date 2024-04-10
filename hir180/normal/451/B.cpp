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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int n;
	int num[100005];
	int a[100005];
	cin >> n;
	for(int i=1;i<=n;i++) cin >> num[i];
	for(int i=1;i<=n;i++) a[i] = num[i];
	sort(a+1,a+n+1);
	int lb = INF,ub = -INF;
	for(int i=1;i<=n;i++)
	{
		if(num[i] != a[i])
		{
			lb = min(lb,i); ub = max(ub,i);
		}
	}
	if(lb == INF)
	{
		puts("yes\n1 1"); return 0;
	}
	//lb~ub
	//lb-1~ub
	//lb~ub+1
	int x[100005];
	for(int i=1;i<=n;i++)
	{
		if(lb <= i && i <= ub) x[i] = num[ub+lb-i];
		else x[i] = num[i];
	}
	for(int i=2;i<=n;i++) if(x[i] < x[i-1]) goto nxt;
	printf("yes\n%d %d\n",lb,ub); return 0; nxt:;

	lb--;
	if(lb == 0) goto nxt2;
	for(int i=1;i<=n;i++)
	{
		if(lb <= i && i <= ub) x[i] = num[ub+lb-i];
		else x[i] = num[i];
	}
	for(int i=2;i<=n;i++) if(x[i] < x[i-1]) goto nxt2;
	printf("yes\n%d %d\n",lb,ub); return 0; nxt2:;
	
	if(ub == n) goto nxt3;
	lb++; ub++;
	for(int i=1;i<=n;i++)
	{
		if(lb <= i && i <= ub) x[i] = num[ub+lb-i];
		else x[i] = num[i];
	}
	for(int i=2;i<=n;i++) if(x[i] < x[i-1]) goto nxt3;
	printf("yes\n%d %d\n",lb,ub); return 0; nxt3:;
	puts("no");
}