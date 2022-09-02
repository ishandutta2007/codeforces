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
int num[105];
int rev[105];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> num[i];
		rev[num[i]]=i;
	}
	int m;
	cin >> m;
	for(int k=1;k<=m;k++)
	{
		int t,a,b;
		cin >> t >> a >> b;
		if(t==2)
		{
			int u=num[a];
			int v=num[b];
			swap(rev[u],rev[v]);
			swap(num[a],num[b]);
		}
		else
		{
			int ans=b-a+1;
			for(int j=a;j<b;j++)
			{
				if(rev[j]<rev[j+1]) ans--;
			}
			cout << ans << endl;
		}
}
}