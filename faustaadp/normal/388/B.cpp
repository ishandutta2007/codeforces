#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,te,e[2020][2020],i,j,K;
void buat(ll aa)
{
	ll ii,Z=1,nw=2;
	for(ii=aa+1;ii<=K;ii++)
	{
		// te++;
		nw++;
		e[nw][Z]=1;
		e[Z][nw]=1;
		Z=nw;
	}
	if(aa==0)
	{
		e[Z][2]=1;
		e[2][Z]=1;
	}
	for(ii=1;ii<=aa;ii++)
	{
		ll nx=++te;
		ll ny=++te;
		if(ii==1)
		{
			e[Z][nx]=1;
			e[nx][Z]=1;
			e[Z][ny]=1;
			e[ny][Z]=1;
		}
		else
		{
			e[nx][nx-2]=1;
			e[nx-2][nx]=1;
			e[nx][nx-1]=1;
			e[nx-1][nx]=1;
			e[ny][ny-3]=1;
			e[ny-3][ny]=1;
			e[ny][ny-2]=1;
			e[ny-2][ny]=1;
		}
		if(ii==aa)
		{
			e[nx][2]=1;
			e[2][nx]=1;
			e[ny][2]=1;
			e[2][ny]=1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	te=40;
	K=30;
	for(i=K;i>=0;i--)
		if(n&(1<<i))
			buat(i);
	cout<<te<<"\n";
	for(i=1;i<=te;i++)
	{
		for(j=1;j<=te;j++)
			if(e[i][j])
				cout<<"Y";
			else
				cout<<"N";
		cout<<"\n";
	}
}