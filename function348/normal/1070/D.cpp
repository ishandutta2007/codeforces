#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=200010,p=1000000007;
int n,k;
long long ans;
int a[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		ans+=a[i-1]/k;
		a[i-1]%=k;
		if (a[i-1]>0&&i>1)
		{
			a[i]-=k-a[i-1];ans++;
			if (a[i]<0) a[i]=0;
			a[i-1]=0;
		}
	}
	if (a[n]>0) ans+=(a[n]-1)/k+1;
	cout<<ans;
	return 0;
}