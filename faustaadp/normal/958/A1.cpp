#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j;
char a[1010][1010],b[1010][1010];
void rot()
{
	ll ii,jj;
	char tem[110][110];
	for(ii=1;ii<=n;ii++)
		for(jj=1;jj<=n;jj++)
			tem[ii][jj]=a[ii][jj];
	for(ii=1;ii<=n;ii++)
		for(jj=1;jj<=n;jj++)
			a[ii][jj]=tem[n-jj+1][ii];
}
void flipx()
{
	ll ii,jj;
	for(ii=1;ii<=n;ii++)
		for(jj=1;jj<=n/2;jj++)
			swap(a[ii][jj],a[ii][n-jj+1]);
}
void flipy()
{
	ll ii,jj;
	for(ii=1;ii<=n/2;ii++)
		for(jj=1;jj<=n;jj++)
			swap(a[ii][jj],a[n-ii+1][jj]);
}
void cek()
{
	ll ii,jj;
	for(ii=1;ii<=n;ii++)
		for(jj=1;jj<=n;jj++)
			if(a[ii][jj]!=b[ii][jj])
				return ;
	cout<<"Yes\n";
	exit(0);
}
void liat()
{
	ll ii,jj;
	cout<<"__\n";
	for(ii=1;ii<=n;ii++)
	{
		for(jj=1;jj<=n;jj++)
			cout<<a[ii][jj];
		cout<<"\n";
	}
	cout<<"##\n";
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>b[i][j];
	for(i=1;i<=4;i++)
	{
		cek();
		flipx();
		cek();
		flipx();
		flipy();
		cek();
		flipx();
		cek();
		flipx();
		flipy();
		rot();
	}
	//liat();
	cout<<"No\n";
}