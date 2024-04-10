#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,a[1010][1010],d[1010][1010][2],X,Y;
ll heya(ll aa,ll bb)
{
	if(aa==0)return 1e18;
	ll H=0;
	while(aa%bb==0)
	{
		H++;
		aa/=bb;
	}
	return H;
}
ll depe(ll aa,ll bb,ll cc)
{

	if(((aa+bb)-(n+n))==1){return 0;}
	if(aa<=0||bb<=0||aa>n||bb>n){return 1e18;}
	//cout<<aa<<" "<<bb<<" "<<cc<<"\n";
	if(d[aa][bb][cc]==-1)
	{
		ll tambah=0;
		if(cc==0)tambah=heya(a[aa][bb],2);
		if(cc==1)tambah=heya(a[aa][bb],5);
		d[aa][bb][cc]=tambah+min(depe(aa,bb+1,cc),depe(aa+1,bb,cc));
	}
	return d[aa][bb][cc];
}
void hey(ll aa,ll bb,ll cc)
{
//	cout<<aa<<" "<<bb<<"\n";
	if(aa==n&&bb==n)return ;
	if(cc==2)
	{
		if(aa<=X&&bb<=Y&&((aa+bb)<(X+Y)))
		{
			if(aa<X)
			{
				cout<<"D";
				hey(aa+1,bb,cc);
			}
			else
			{
				cout<<"R";
				hey(aa,bb+1,cc);
			}
		}
		else
		if(aa<n)
		{
			cout<<"D";
			hey(aa+1,bb,cc);
		}
		else
		{
			cout<<"R";
			hey(aa,bb+1,cc);
		}
	}
	else
	if(depe(aa,bb+1,cc)<depe(aa+1,bb,cc))
	{
		cout<<"R";
		hey(aa,bb+1,cc);
	}
	else
	{
		cout<<"D";
		hey(aa+1,bb,cc);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]==0)
			{
				X=i;
				Y=j;
			}
	memset(d,-1,sizeof(d));
	//return 0;
	if(min(depe(1,1,0),depe(1,1,1))>1&&X!=0)
	{
		//return 0;
		cout<<1<<"\n";
		//return 0;
		hey(1,1,2);
	}
	else
	if(depe(1,1,0)<depe(1,1,1))
	{
		//return 0;
		cout<<depe(1,1,0)<<"\n";
		hey(1,1,0);
	}
	else 
	{
		//return 0;
		cout<<depe(1,1,1)<<"\n";
		hey(1,1,1);
	}
	cout<<"\n";
}