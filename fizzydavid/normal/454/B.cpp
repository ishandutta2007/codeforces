/*
	Author  : JZdavid
	From    : CF
	Problem : 454B
	Time    : 2014/8/2
	Verdict : Accepting
*/
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
int n,a[100111],b[100111];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[(n-i)%n]==b[0]&&a[n-1-i]==b[n-1])
		{
			bool ok=1;
			for(int j=0;j<n;j++)
			{
				int k=((n-i)%n+j)%n;
				if(b[j]!=a[k]){ok=0;break;}
			}
			if(ok==1)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	puts("-1");
// 	system("pause");
	return 0;
}