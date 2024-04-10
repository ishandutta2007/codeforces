#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
L n,m,l,r;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	l=max(1ll,m-n);
	r=min(m/2-(!(m%2)),n);
	cout<<max(r-l+1,0ll);
	return 0;
}