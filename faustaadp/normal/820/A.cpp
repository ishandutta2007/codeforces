#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,v0,v1,a,l,vv,hs,n;
int main()
{
	cin>>c>>v0>>v1>>a>>l;
	
	vv=v0;
	while(1)
	{
		hs++;
		n=n+vv;
		if(n>=c)
			break;
		if(vv<v1)
			vv=min(v1,vv+a);
		n=n-l;
	}
	cout<<hs<<endl;
}