#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l[MAXN],r[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		r[i]+=l[i];	
	}
	for(int i=2;i<=n;i++)
		r[i]=min(r[i],r[i-1]+1);
	for(int i=n-1;i>=1;i--)
		r[i]=min(r[i],r[i+1]+1);
	for(int i=1;i<=n;i++)
		if(r[i]<l[i]) {puts("-1"); return 0;}
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=(ll)r[i]-l[i];
	printf("%I64d\n",sum);
	for(int i=1;i<=n;i++)
		printf("%d ",r[i]);
	return 0;
}