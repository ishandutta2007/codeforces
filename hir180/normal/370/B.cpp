//Bokann ga bokka--nn!!
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
bool have[105][105]={};
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int g;
		cin >> g;
		for(int j=0;j<g;j++)
		{
			int f;
			cin >> f;
			have[i][f]=true;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			for(int k=1;k<=100;k++)
			{
				if(!have[i][k] && have[j][k]) goto ok;
			}
			puts("NO");
			goto end;
ok:;
		}
		puts("YES");
		end:;
	}
}