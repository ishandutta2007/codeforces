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
	int num[105];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		ans+=num[i];
	}
	int sum=-10;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int g=0;
			for(int k=i;k<=j;k++)
			{
				if(num[k]) g--;
				else g++;
			}
			sum=max(sum,g);
		}
	}
	cout << sum+ans << endl;
}