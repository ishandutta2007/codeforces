#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,q,i,a[202020],p[202020],temA,temB,temC,temD,ta,L,R,C;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		p[i]=p[i-1]+a[i];
	temA=1;
	temB=a[1];
	while(q--)
	{
		cin>>ta;
		if(ta<temB)
		{
			temB-=ta;
		}
		else
		if(ta>=p[n]-p[temA]+temB)
		{
			temA=1;
			temB=a[1];
		}
		else
		{
			L=temA+1;
			R=n;
			temC=-1;
			temD=-1;
			while(L<=R)
			{
				C=(L+R)/2;
			//	cout<<"C"<<C<<" "<<p[C-1]-p[temA]+temB<<"\n";
				if((p[C-1]-p[temA]+temB)<=ta)
				{
					temC=C;
				//	cout<<"tC"<<temC<<"\n";
					temD=ta-(p[C-1]-p[temA]+temB);
					L=C+1;
				}
				else
					R=C-1;
			}
			temA=temC;
			temB=a[temA]-temD;
		}
	//	cout<<temA<<" "<<temB<<"\n";
		cout<<n-temA+1<<"\n";
	}
}