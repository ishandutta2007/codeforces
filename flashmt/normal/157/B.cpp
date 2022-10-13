#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n,a[111],ans=0;
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for (int i=n-1;i>=0;i-=2) ans+=a[i]*a[i]-(i?a[i-1]*a[i-1]:0);
	printf("%.9lf\n",acos(-1.0)*ans);
}