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
int p,n,a[311];
set<int>s;
int main()
{
	int ans=-1;
	cin>>p>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s.insert(a[i]%p);
		if(s.size()!=i){ans=i;break;}
	}
	cout<<ans;
// 	system("pause");
	return 0;
}