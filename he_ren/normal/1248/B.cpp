#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int mid = n>>1;
	
	ll p=0,q=0;
	for(int i=1; i<=mid; ++i) p+=a[i];
	for(int i=mid+1; i<=n; ++i) q+=a[i];
	
	cout<<p*p + q*q;
	return 0;
}