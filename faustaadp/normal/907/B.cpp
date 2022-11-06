#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,ie,je,v[10][10],x,y,bo;
char tc,a[1010][1010],c[1010][1010];
int main()
{
	for(i=1;i<=11;i++)
	{
		if(i==4||i==8)
			cin.ignore();
		else
		{
			je=0;
			ie++;
		for(j=1;j<=11;j++)
		{
			if(j==4||j==8)
				1+1==2;
			else
			{
				cin>>tc;
				je++;
				a[ie][je]=tc;
				c[ie][je]=a[ie][je];
				if(tc!='.')
					v[(ie-1)/3][(je-1)/3]++;
			}
	//		cout<<i<<" "<<j<<"\n";
		}
		}
	}
	cin>>x>>y;
	ie=0;
	je=0;
	if(v[(x-1)%3][(y-1)%3]==9)
		bo=1;
	for(i=1;i<=11;i++)
	{
		if(i==4||i==8)
			cout<<"\n";
		else
		{
			je=0;
			ie++;
			for(j=1;j<=11;j++)
			{
				if(j==4||j==8)
					cout<<" ";
				else
				{
					je++;
					if(bo==1)
					{
						if(a[ie][je]=='.')
							cout<<'!';
						else
						cout<<a[ie][je];
					}
					else
					{
						if(((x-1)%3==(ie-1)/3)&&(y-1)%3==(je-1)/3&&a[ie][je]=='.')
							cout<<'!';
						else
							cout<<a[ie][je];
					}
				}
			//	cout<<ie<<" "<<je<<"\n";
			}
			cout<<"\n";
		}
	}
}