#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,j;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			if(i%2==1||(i%4==2&&j==m)||(i%4==0&&j==1))
				cout<<'#';
			else
				cout<<'.';
		cout<<"\n";
	}
}