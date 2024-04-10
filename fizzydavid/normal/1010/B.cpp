//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
int n,m;
int query(int x)
{
	cout<<x<<endl;
	fflush(stdout);
	int ret;
	cin>>ret;
	if(!(ret==-1||ret==1))exit(0);
	return ret;
}
int f[33];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		f[i]=query(1);
	}
	int l=1,r=n;
	while(true)
	{
		for(int i=1;i<=m;i++)
		{
			int mid=l+r>>1;
			int ret=query(mid);
			ret=ret*f[i];
			if(ret==1)l=mid+1;
			else r=mid-1;
		}
	}
	return 0;
}