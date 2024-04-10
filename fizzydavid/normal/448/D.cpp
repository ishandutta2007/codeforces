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
long long n,m,k;
int ok(long long x)
{
	long long cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		cnt1+=min(m,(x-1)/i);
		cnt2+=min(m,x/i);
	}
	if(k<=cnt1)return -1;
	else if(cnt1<k&&k<=cnt2)return 0;
	else if(cnt2<k)return 1;
}
int main()
{
	cin>>n>>m>>k;
	long long l=0,r=n*m,m;
	while(l<=r)
	{
		m=(l+r)/2;
		if(ok(m)==-1)r=m-1;
		else if(ok(m)==1)l=m+1;
		else break;
	}
	cout<<m;
// 	system("pause");
	return 0;
}