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
int e[105];
int main(){
	int n,m;
	cin >> n >> m;
	vector<int>num;
	e[0]=e[1]=1;
	for(int i=2;i<=100;i++) e[i]=(e[i-1]+e[i-2])%1000000000;
	for(int i=0;i<n;i++) { int r; cin >> r; num.pb(r);}
	for(int i=0;i<m;i++)
	{
		int t;
		cin >> t;
		if(t==1)
		{
			int a,b;
			cin >> a >> b;
			num[a-1]=b;
		}
		else
		{
			int a,b;
			cin >> a >>b;
			long long ans=0;
			for(int i=0;i<=b-a;i++)
			{
				ans+=(1LL*e[i]*num[a+i-1])%1000000000;
				ans%=1000000000;
			}
			cout << ans << endl;
		}
	}
}