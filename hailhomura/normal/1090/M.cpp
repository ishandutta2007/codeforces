#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long 
#define rev(i,a,n) for(int i=n;i>=a;i--)

const int MOD = 1e9+7;

int n,k,cnt,h[100005],maks=0;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	rep(i,1,n)
	{
		cin>>h[i];
	}
	rep(i,1,n-1)
	{
		if(h[i+1]!=h[i])
		{
			cnt++;
			if(cnt>maks) maks=cnt;
		}
		if(h[i+1]==h[i])
		{
			cnt=0;
		}
	}
	cout<<maks+1;
	return 0;
}