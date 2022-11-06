#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,b[1010],f[1010];
int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	b[1]=1;
	f[1]=1;
	f[2]=1;
	for(i=3;i<=1000;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>1000)
			break;
		b[f[i]]=1;
	}
	cin>>n;
	for(i=1;i<=n;i++)
		if(b[i])
			cout<<"O";
		else
			cout<<"o";
	cout<<"\n";
}