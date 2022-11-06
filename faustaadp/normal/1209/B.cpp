#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,has,ta,tb;
char a[1010][1010];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i][0];
	for(i=1;i<=n;i++)
	{
		cin>>tb>>ta;
		for(j=1;j<ta;j++)
			a[i][j]=a[i][0];
		ll tom=0;
		for(j=ta;j<=500;j++)
		{
			a[i][j]=a[i][j-1];
			if(tom==0)
			{
				//cout<<"xx\n";
				if(a[i][j]=='1')a[i][j]='0';
				else a[i][j]='1';
				//else cout<<"A\n";
			}
			tom++;
			tom%=tb;
		}
	}
	// for(i=1;i<=n;i++)
	// {
	// 	for(j=0;j<=10;j++)
	// 		cout<<a[i][j];
	// 	cout<<"\n";
	// }
	for(i=0;i<=500;i++)
	{
		ll hz=0;
		for(j=1;j<=n;j++)
			if(a[j][i]=='1')
				hz++;
		has=max(has,hz);
	}
	cout<<has<<"\n";

}