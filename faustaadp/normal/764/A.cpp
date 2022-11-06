#include<bits/stdc++.h>
using namespace std;
long long  x,y,z,hs;
long long  fpb(long long fa,long long fb)
{
	if(fb==0)
		return fa;
	else
		return fpb(fb,fa%fb);
}
int main()
{
	cin>>x>>y>>z;
	hs=fpb(x,y);
	hs=(x*y)/hs;
	cout<<z/hs<<endl;
}