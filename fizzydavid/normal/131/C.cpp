#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
ll n,m,t,ans;
ll cal(int x,int y)
{
	ll res=1;
//	for(int i=x-y+1;i<=x;i++)res*=i;
	for(int i=1;i<=y;i++)
	{
		res*=x-i+1;
		res/=i;
	}
	return res;
}
int main()
{
	cin>>n>>m>>t;
	for(int i=1;t-i>=4;i++)
	{
		if(i>m)continue;
		if(t-i>n)continue;
		ans+=cal(m,i)*cal(n,t-i);
	}
	cout<<ans;
 //	system("pause");
	return 0;
}