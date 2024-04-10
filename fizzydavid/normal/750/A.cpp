//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,k;
int main()
{
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i*(i+1)/2*5+k<=240)
		{
			ans=max(ans,i);
		}
	}
	cout<<ans<<endl;
	return 0;
}