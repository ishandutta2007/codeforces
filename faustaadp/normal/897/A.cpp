#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,l,r;
char c[101010],c1,c2;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>c[i];
	while(m--)
	{
		cin>>l>>r>>c1>>c2;
		for(i=l;i<=r;i++)
		{
			if(c[i]==c1)
			{
				c[i]=c2;
			}
		}
	}
	for(i=1;i<=n;i++)
		cout<<c[i];
	cout<<"\n";
}