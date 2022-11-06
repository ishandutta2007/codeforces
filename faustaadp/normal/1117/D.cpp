#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,has,mo=1000000007,i,mat[110][110],M[110][110],mt[110][110];
ll pan(ll aa)
{
	ll ii,jj,kk;
	for(ii=1;ii<=m;ii++)mat[ii][ii]=1;
	while(aa>0)
	{
		if(aa%2==1)
		{
			memset(mt,0,sizeof(mt));
			for(ii=1;ii<=m;ii++)
				for(jj=1;jj<=m;jj++)
					for(kk=1;kk<=m;kk++)
						mt[ii][jj]=(mt[ii][jj]+mat[ii][kk]*M[kk][jj])%mo;
			for(ii=1;ii<=m;ii++)
				for(jj=1;jj<=m;jj++)
					mat[ii][jj]=mt[ii][jj];
		}
		memset(mt,0,sizeof(mt));
		for(ii=1;ii<=m;ii++)
			for(jj=1;jj<=m;jj++)
				for(kk=1;kk<=m;kk++)
					mt[ii][jj]=(mt[ii][jj]+M[ii][kk]*M[kk][jj])%mo;
		for(ii=1;ii<=m;ii++)
			for(jj=1;jj<=m;jj++)
				M[ii][jj]=mt[ii][jj];
		aa/=2;
	}
	ll H=0;
	/*for(ii=1;ii<=m;ii++)
	{
		for(jj=1;jj<=m;jj++)
			cout<<mat[ii][jj]<<" ";
		cout<<"\n";
	}*/
	for(ii=1;ii<=m;ii++)H=(H+mat[1][ii])%mo;
	return H;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	if(n<m)cout<<1<<"\n";
	else
	{
		for(i=1;i<m;i++)M[i][i+1]=1;
		M[m][m]=1;
		M[m][1]=1;
		cout<<pan(n)<<"\n";
	}
}