#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int k=(n+1)/2;
	long long x=0,y=0;
	for(int i=1;i<=k;i++)
		x+=a[i];
	for(int i=k+1;i<=n;i++)
		y+=a[i];
	cout<<x*x+y*y<<endl; 
	return 0;
}