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
int n,d,a[100111];
ll ans;
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int j=1;
	for(int i=1;i<n;i++)
	{
		while(a[j]-a[i]<=d&&j<=n)j++;
//		cout<<i<<" "<<j<<endl;
		ans+=max(0ll,1ll*(j-i-1)*(j-i-2)/2);
	}
	cout<<ans;
// 	system("pause");
	return 0;
}