#include<bits/stdc++.h>
using namespace std;
long long n,i,x,y,mx,my,mmx,mmy,hs;
string s;
map <string,long long> ss;
int main()
{
	cin>>n;
	my=92983923892938238;
	mmy=my;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		my=min(my,y);
		mmx=max(mmx,x);
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>y;
		mx=max(mx,x);
		mmy=min(mmy,y);
	}
//	cout<<mx<<" "<<my<<endl;
//	cout<<mmx<<" "<<my<<endl;
	hs=max((mx-my),(mmx-mmy));
	cout<<max(0LL,hs)<<endl;
}