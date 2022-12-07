#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
int num[5],n,ans,k;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int a;
		cin>>a;
		num[a]++;
	}
	ans+=num[4];
	k=min(num[1],num[3]);
	ans+=k;
	num[1]-=k;
	num[3]-=k;
	ans+=num[3];
	ans+=num[2]/2;
	num[2]%=2;
	if(num[2]==1)
	{
		ans++;
		num[1]-=2;
	}
	ans+=num[1]/4;
	if(num[1]%4!=0 && num[1]>0)ans++;
	cout<<ans<<endl;
	return 0;
}