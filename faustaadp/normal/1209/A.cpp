#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],b[101010],has,j;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	for(i=1;i<=100;i++)
	{
		if(b[i]==1)
		{
			has++;
			for(j=i;j<=100;j+=i)
				b[j]=0;
		}
	}
	cout<<has<<"\n";

}