#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n;
int a[1010];
multiset <int> S;
int gcd(int a,int b) { return b?gcd(b,a%b):a;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*n;i++) 
	{
		int x;scanf("%d",&x);
		S.insert(x);
	}
	
	for (int i=1;i<=n;i++)
	{
		multiset <int>::iterator it=S.end();
		it--;
		int x=(*it);
		S.erase(it);
		a[i]=x;
		for (int j=1;j<i;j++) S.erase(S.find(gcd(a[j],a[i]))),S.erase(S.find(gcd(a[j],a[i])));
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}