#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll d[1010],i,tt,n;
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	d[1]=1;
	for(i=1;i<=1000;i++)
	{
		if(i%2==1)
			tt++;
		d[i]=d[i-1]+tt;
	}
	//for(i=1;i<=10;i++)
	//	cout<<i<<" "<<d[i]<<"\n";
	cin>>n;
	cout<<d[n]<<"\n";
}