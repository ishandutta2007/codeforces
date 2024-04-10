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
#define geta 100005
int bit[(1<<18)+1];
int f(int x){ return x&-x;}
void add(int i,int x){  for(int s=i;s<=(1<<18);s+=f(s)) bit[s]+=x;}
int sum(int i){ int ret=0;for(int s=i;s>0;s-=f(s)) ret+=bit[s]; return ret;}
int main()
{
	srand((unsigned int)time(NULL));
	int num[2005],n; scanf("%d",&n);
	for(int i=1;i<=n;i++) { scanf("%d",&num[i]); num[i]=abs(num[i]);}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		int le=0,ri=0;
		for(int j=1;j<i;j++) le+=(num[j]<num[i]); 
		for(int j=i+1;j<=n;j++) ri+=(num[j]<num[i]);
		ret+=min(le,ri);
	}
	printf("%d\n",ret);
}