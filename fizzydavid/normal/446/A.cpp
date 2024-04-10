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
int n,a[100111],l[100111],r[100111],mx=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),l[i]=1,r[i]=1;
	for(int i=2;i<=n;i++)if(a[i]>a[i-1])l[i]=l[i-1]+1;
	for(int i=n-1;i>=1;i--)if(a[i]<a[i+1])r[i]=r[i+1]+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]+1<a[i+1])mx=max(mx,r[i+1]+1+l[i-1]);
		else mx=max(mx,max(l[i-1],r[i+1])+1);
	}
	cout<<mx;
//	system("pause");
	return 0;
}