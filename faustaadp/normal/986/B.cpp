#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[1010101],pos[1010101],tukar;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	tukar=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			tukar++;
			ll tem1=a[i],tem2=pos[i];
			swap(a[i],a[pos[i]]);
			pos[i]=i;
			pos[tem1]=tem2;
		}
	}
	if((n*3)%2==tukar%2)
		cout<<"Petr\n";
	else
		cout<<"Um_nik\n";
}