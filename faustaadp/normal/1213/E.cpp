#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,x[1010][1010],i,b[1010],j;
string s,t,z,has;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	cin>>s;
	cin>>t;
	if(s[0]==s[1]&&t[0]==t[1])
	{
		cout<<"YES\n";
		if(s==t)
		{
			for(i=1;i<=n;i++)
				cout<<"abc";
			cout<<"\n";
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				cout<<s[0];
				cout<<t[0];
			}
			b[s[0]]=1;
			b[t[1]]=1;
			for(i=1;i<=n;i++)
			{
				for(j='a';j<='c';j++)
					if(b[j]==0)
						cout<<char(j);
			}
			cout<<"\n";
		}
	}
	else
	if(s[0]==s[1]||t[0]==t[1])
	{
		if(t[0]==t[1])
			swap(s,t);
		b[s[0]]=1;
		b[t[0]]=1;
		b[t[1]]=1;
		cout<<"YES\n";
		if(b['a']==1&&b['b']==1&&b['c']==1)
		{
			for(i=1;i<=n;i++)
			{
				cout<<s[0];
				cout<<t[1];
				cout<<t[0];	
			}
			cout<<"\n";
		}
		else
		{
			string u=t;
			char ct;
			for(i='a';i<='c';i++)
				if(b[i]==0)
					ct=char(i);
			if(u[0]==s[0])u[0]=ct;	
			else if(u[1]==s[0])u[1]=ct;	
			for(i=1;i<=n;i++)
			{
				cout<<s[0];
				cout<<u;
			}
			cout<<"\n";
		}
	}
	else
	{	
		x[s[0]][s[1]]=1;
		x[t[0]][t[1]]=1;
		z="abc";
		do
		{
			if(x[z[0]][z[1]]||x[z[1]][z[2]])continue;
			else
			{
				for(i=1;i<=n;i++)has+=z[0];
				for(i=1;i<=n;i++)has+=z[1];
				for(i=1;i<=n;i++)has+=z[2];
				cout<<"YES\n";
				cout<<has<<"\n";
				return 0;
			}
		}
		while(next_permutation(z.begin(),z.end()));
		cout<<"NO\n";
	}
}