//E?Nanndatte?
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
typedef long long ll;
#define mod 1000000009
int n;
int main(){
	cin >> n;
	int cor[5][4];
	int minx=INF,maxx=-INF;
	int miny=INF,maxy=-INF;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin >> cor[i][j]
			;
			if(j%2==0)
			{
				minx=min(minx,cor[i][j]);
				maxx=max(maxx,cor[i][j]);
			}
			else
			{
				miny=min(miny,cor[i][j]);
				maxy=max(maxy,cor[i][j]);
			}
		}
		sum+=1LL*(cor[i][2]-cor[i][0])*(cor[i][3]-cor[i][1]);
	}

	long long X=(maxx-minx)*1LL;
	long long Y=(maxy-miny)*1LL;
	if(sum==X*Y && X==Y) puts("YES");
	else puts("NO");
}