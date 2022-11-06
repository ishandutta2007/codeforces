#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll d[2020202],n,jumno,sudah[101010],has,i;
string s;
ll depe(ll aa)
{
	if(d[aa]==-1)
	{
		d[aa]=0;
		ll ii,O=0;
		bool S[10],S2[10];
		for(ii=0;ii<=9;ii++)
		{
			S[ii]=0;
			S2[ii]=0;
		}
		for(ii=0;ii<n;ii++)
		{
			if((aa&(1<<ii)))
			{
				if(!S2[s[ii]-'0'])
					O++;
				S2[s[ii]-'0']=1;
				continue;
			}
			if(S[s[ii]-'0'])	continue;
			d[aa]+=depe((aa|(1<<ii)));
			S[s[ii]-'0']=1;
		}
		//cout<<O<<" "<<jumno<<"\n";
		d[aa]+=(O==jumno);
	}
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(!sudah[s[i]])
			jumno++;
		sudah[s[i]]=1;
	}
	for(i='0';i<='9';i++)
		sudah[i]=0;
	memset(d,-1,sizeof(d));
	sudah['0']=1;
	for(i=0;i<n;i++)
	{
		if(sudah[s[i]]==0)
			has+=depe(1<<i);
		sudah[s[i]]=1;
	}
	cout<<has<<"\n";
}