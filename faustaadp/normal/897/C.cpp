#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll d[101010],i,q,a,b;
string s;
char rmt(ll aa,ll bb)
{
//	cout<<aa<<" "<<bb<<"\n";
	if(aa==0)
	{
		string z="What are you doing at the end of the world? Are you busy? Will you save us?";
		return z[bb-1];
	}
	else
	{
		if(1<=bb&&bb<=34)
		{
			string z="What are you doing while sending \"";
			return z[bb-1];
		}
		else
		if(34+1<=bb&&bb<=34+d[aa-1])
			return rmt(aa-1,bb-34);
		if(34+d[aa-1]+1<=bb&&bb<=34+d[aa-1]+32)
		{
			string z="\"? Are you busy? Will you send \"";
			return z[bb-(34+d[aa-1]+1)];
		}
		else
		if(34+d[aa-1]+32+1<=bb&&bb<=34+d[aa-1]+32+d[aa-1])
			return rmt(aa-1,bb-(34+d[aa-1]+32));
		else
		{
			string z="\"?";
			return z[bb-(34+d[aa-1]+32+d[aa-1]+1)];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	d[0]=75;
	for(i=1;i<=53;i++)
	{
		d[i]=68+2*d[i-1];
	}
	for(i=54;i<=100000;i++)
		d[i]=d[i-1];
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		if(b>d[a])
			cout<<'.';
		else
			cout<<rmt(a,b);
	}
	cout<<"\n";
}