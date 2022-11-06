#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,a[1010][1010],te,B[1010],K[1010];
void buat(ll aa,ll bb)
{
	ll cc=bb+3,ii,jj;
	for(ii=aa;ii<=(aa+3);ii++)
	{
		if(ii%2==1)
		{		
			for(jj=bb;jj<=cc;jj++)
			{
				a[ii][jj]=te;
				te++;
			}
		}
		else
		{
			for(jj=cc;jj>=bb;jj--)
			{
				a[ii][jj]=te;
				te++;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i+=4)
		for(j=1;j<=n;j+=4)
			buat(i,j);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			B[i]^=a[i][j];
			K[j]^=a[i][j];
		}
	// for(i=1;i<=n;i++)
	// {
	// 	// if(B[i]!=0||K[i]!=0)
	// 	// {
	// 	// 	cout<<i<<"_ "<<B[i]<<" "<<K[i]<<"\n";
	// 	// }
	// 	//cout<<B[i]<<" "<<K[j]<<"\n";	
	// }
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(j==n)
				cout<<a[i][j]<<"\n";
			else
				cout<<a[i][j]<<" ";
}