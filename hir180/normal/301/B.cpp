//CF301
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
long long d[105][105];
long long gen[105]={};
int V;
long long D;
void warshall_floyd(){
	for(int k=1;k<=V;k++){
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}

int main(){
	cin >> V >> D;
	for(int i=2;i<V;i++)
	{
		cin >> gen[i];
	}
	P cor[105];
	for(int i=1;i<=V;i++)
	{
		int f,s;
		cin >> f >> s;
		cor[i].first=f;
		cor[i].second=s;
	}
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			if(i==j) continue;
			int dis=abs(cor[i].first-cor[j].first);
			dis+=abs(cor[i].second-cor[j].second);
			long long cost=1LL*dis*D;
			cost-=gen[j];
			d[i][j]=cost;
		}
	}
	warshall_floyd();
	printf("%lld\n",d[1][V]);
}