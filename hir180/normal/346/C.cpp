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
vector<int>num;
bool exc[100005]={};
int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x); num.pb(x);
	}
	sort(num.begin(),num.end()); num.erase(unique(num.begin(),num.end()),num.end());
	int a,b,rep=0; scanf("%d %d",&a,&b);
	if(a==b) return puts("0");
	while(1)
	{
		rep++;
		int res=a;
		bool v=false; int r=num.size()-1;
		for(int i=num.size()-1;i>=0;i--)
		{
			if(a-a%num[i]>=b) {v=true;res=min(res,a-a%num[i]);}
			else swap(num[r--],num[i]);
		}
		if(res==a&&!v) return !printf("%d\n",rep+a-b-1);
		else if(res==a) res--;
		if(res==b) return !printf("%d\n",rep);
		a=res; num.resize(r+1);
	}
}