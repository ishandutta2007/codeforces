#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll n,q,c,i,ta,tb,tc,tt,j,k,jk,p[12][110][110],i1,j1,i2,j2;
vector<ll> v[110][110];
int main()
{
	fast
	cin>>n>>q>>c;
	for(i=1;i<=n;i++)
	{
		cin>>ta>>tb>>tc;
		v[ta][tb].push_back(tc);
	}
	for(tt=0;tt<=c;tt++)
	{
	//	cout<<tt<<"\n";
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=100;j++)
			{
				jk=0;
				if(v[i][j].size()>0)
				{
					jk=0;
					for(k=0;k<v[i][j].size();k++)
					{
						//cout<<i<<" "<<j<<"\n";
						jk=jk+(tt+v[i][j][k])%(c+1);
					}
			//		cout<<jk<<"\n";
				}
				p[tt][i][j]=p[tt][i-1][j]+p[tt][i][j-1]-p[tt][i-1][j-1]+jk;
				//cout<<tt<<" "<<i<<" "<<j<<" "<<p[tt][i][j]<<"\n";
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>ta>>i1>>j1>>i2>>j2;
		ta=ta%(c+1);
		cout<<p[ta][i2][j2]-p[ta][i1-1][j2]-p[ta][i2][j1-1]+p[ta][i1-1][j1-1]<<"\n";
	}
}