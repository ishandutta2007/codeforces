#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,has;
char a[202020];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i+=2)
		if(a[i]==a[i+1])
		{
			if(a[i]=='a')
				a[i]='b';
			else
				a[i]='a';
			has++;
		}
	cout<<has<<"\n";
	for(i=1;i<=n;i++)
		cout<<a[i];
	cout<<"\n";
}