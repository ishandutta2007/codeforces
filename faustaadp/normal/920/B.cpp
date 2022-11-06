#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i,b[5050],ta,tb,hz,j;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
		{
			cin>>ta>>tb;
			hz=0;
			for(j=ta;j<=tb;j++)
			{
				if(b[j]==0)
				{
					b[j]=1;
					hz=j;
					break;
				}
			}
			if(i==n)
				cout<<hz<<"\n";
			else
				cout<<hz<<" ";
		}
	}
}