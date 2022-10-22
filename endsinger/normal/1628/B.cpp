#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=30;
int n,a[M][M],b[M][M][M];
string s[N];
void sol()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		if(s[i].size()==1||(s[i].size()==2&&s[i][0]==s[i][1])||(s[i].size()==3&&s[i][0]==s[i][2]))
		{
			cout<<"YES\n";
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].size()==2)
		{
			int c1=s[i][0]-'a',c2=s[i][1]-'a';
			for(int j=0;j<26;j++)
			{
				if(b[c2][c1][j])
				{
					cout<<"YES\n";
					return;
				}
			}
			if(a[c2][c1])
			{
				cout<<"YES\n";
				return;
			}
			a[c1][c2]=1;
		}
		if(s[i].size()==3)
		{
			int c1=s[i][0]-'a',c2=s[i][1]-'a',c3=s[i][2]-'a';
			if(b[c3][c2][c1])
			{
				cout<<"YES\n";
				return;
			}
			if(a[c3][c2])
			{
				cout<<"YES\n";
				return;
			}
			b[c1][c2][c3]=1;
		}
	}
	cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
		sol();
	return 0;
}