#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<string>
#include<set>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
const ll INF=1<<30;
const ll LINF=1ll<<61;
const double eps=1e-7;
int n,a1,b1,a2,b2;
int main()
{
	cin>>n;
	int x,y;cin>>x>>y;a1=a2=x;b1=b2=y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		a1=min(a1,x);
		a2=max(a2,x);
		b1=min(b1,y);
		b2=max(b2,y);
	}
	cout<<1ll*max(a2-a1,b2-b1)*max(a2-a1,b2-b1)<<endl;
	return 0;
}