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
const int INF=1<<28;
const long long MOD=1000000007;
typedef long long ll;
ll cal(ll x)
{
	while(x<0)x+=MOD;
	x=x%MOD;
	return x;
}
int x,y,k;
int main()
{
	cin>>x>>y>>k;
	if(k%6==1)cout<<cal(x);
	else if(k%6==2)cout<<cal(y);
	else if(k%6==3)cout<<cal(y-x);
	else if(k%6==4)cout<<cal(-x);
	else if(k%6==5)cout<<cal(-y);
	else cout<<cal(x-y);
// 	system("pause");
	return 0;
}