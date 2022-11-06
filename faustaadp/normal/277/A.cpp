#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,i,ta,tb,p[101010],has,j,k,b[101010];
ll isi[110][110];
ll yayaya;
ll car(ll aa)
{
	if(p[aa]==aa)
		return aa;
	else
		return p[aa]=car(p[aa]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		cin>>ta;
		if(ta!=0)yayaya=1;
		while(ta--)
		{
			cin>>tb;
			isi[i][tb]=1;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=m;k++)
				if(isi[i][k]==isi[j][k]&&isi[j][k]==1)
					p[car(i)]=car(j);
	for(i=1;i<=n;i++)
	{
		if(!b[car(i)])has++;
		b[car(i)]=1;
	}
	if(yayaya)
		has--;
	cout<<has<<"\n";
}