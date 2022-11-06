#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,L1=-1,L2=-1,R1=-1,R2=-1;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)if(s[i]=='['){L1=i;break;}
	for(i=(n-1);i>=0;i--)if(s[i]==']'){R1=i;break;}
	if(L1!=-1&&R1!=-1)
	{
		for(i=L1;i<=R1;i++)if(s[i]==':'){L2=i;break;}
		for(i=R1;i>=L1;i--)if(s[i]==':'){R2=i;break;}
		if(L2<R2&&L2!=-1&&R2!=-1)
		{
			ll jum=0;
			for(i=L2;i<=R2;i++)
				jum+=(s[i]=='|');
			cout<<jum+4<<"\n";
		}
		else
			cout<<-1<<"\n";
	}
	else cout<<-1<<"\n";
}