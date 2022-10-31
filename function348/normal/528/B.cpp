#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=200010;
PII a[N];
int cmp(PII a,PII b) { return a.SC<b.SC;}
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,r;
		scanf("%d%d",&x,&r);
		a[i]=MP(x-r,x+r);
	}
	sort(a+1,a+1+n,cmp);
	int mx=-2000000000,cnt=0;
	for (int i=1;i<=n;i++)
	if (a[i].FR>=mx)
	{
		cnt++;
		mx=a[i].SC;
	}
	cout<<cnt<<endl;
	return 0;
}