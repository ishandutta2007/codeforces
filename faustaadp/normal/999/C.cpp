#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,d[404040],tempe,j,b[404040];
char las;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	cin>>s;
	for(i=0;i<n;i++)
		d[s[i]]++;
	for(i='a';i<='z';i++)
	{
		if(d[i]>=k)
		{
			for(j=0;j<n;j++)
			{
				if(s[j]==char(i))
				{
					b[j]=1;
					k--;
					if(k==0)
						break;
				}
			}
			las=i;
			break;
		}
		else
			k-=d[i];
	}
	for(i=0;i<n;i++)
	{
		if(s[i]>=las&&b[i]==0)
			cout<<s[i];
	}
	cout<<"\n";
}