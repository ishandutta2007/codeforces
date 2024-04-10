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
int n,a,b;
int main()
{
	cin>>n>>a>>b;
	if(b==0&&a==n-1&&n!=1)cout<<"-1\n";
	else if(n==1)
	{
		if(b==0)cout<<"1";else cout<<"-1";
	}
	else if(b==0)
	{
		cout<<"1 1";
		for(int i=1;i<=a;i++)cout<<" "<<i+1;
		for(int i=a+3;i<=n;i++)cout<<" "<<a+1;
	}
	else
	{
		cout<<"1";
		for(int i=1;i<=b;i++)
		{
			cout<<" "<<(1<<i);
		}
		int max=(1<<b);
		for(int i=1;i<=a;i++)cout<<" "<<max+i;
		for(int i=a+b+2;i<=n;i++)cout<<" "<<max+a;
	}
// 	system("pause");
	return 0;
}