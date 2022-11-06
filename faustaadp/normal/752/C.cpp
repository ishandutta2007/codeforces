#include<bits/stdc++.h>
using namespace std;
int n,i,hs;
bool ba;
char c,h,v;
int main()
{
	cin>>n;
	h=' ';v=' ';hs=1;
	for(i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='R'||c=='L')
		{
			if((h!=' '&&h!=c))
			{
				hs++;
				h=c;
				v=' ';
			}
			else
				h=c;
		}
		else
		{
			if(v!=' '&&v!=c)
			{
				hs++;
				v=c;
				h=' ';
			}
			else
				v=c;
		}
	}
	cout<<hs<<endl;
}