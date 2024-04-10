#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300010
#define ll long long
using namespace std;
ll num[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
		int l=1,r=n; 
		while(num[l]>=l-1) l++;
		l--;
		while(num[r]>=n-r) r--;
		r++;
		puts((l>=r)?"Yes":"No");
	}
	return 0;
}