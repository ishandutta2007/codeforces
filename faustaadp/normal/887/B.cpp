#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,j,ta;
char c[1010][1010];
bool be[999010],b[1010];
void rmt(string zz)
{
	//cout<<zz<<"\n";
	if(zz.length()>0)
		be[(ll)stoi(zz)]=1;
	ll ii,jj;
	for(ii=1;ii<=n;ii++)
	{
		for(jj=1;jj<=6;jj++)
		{
			if(!b[ii])
			{
				b[ii]=1;
				rmt(zz+char(c[ii][jj]));
				b[ii]=0;
			}
		}
	}
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=6;j++)
		{
			cin>>ta;
			c[i][j]=(ta+'0');
		}	
	rmt("");
	for(i=1;i<=15211;i++)
	{
		if(!be[i])
		{
			cout<<i-1<<"\n";
			return 0;
		}
	}
}