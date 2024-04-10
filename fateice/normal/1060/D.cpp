#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a[100010],b[100010];
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
	  p+=max(a[i],b[i]);
	p+=n;
	cout<<p;
	return 0;
}