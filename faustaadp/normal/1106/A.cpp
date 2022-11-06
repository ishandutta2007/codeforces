#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,j,has;
char a[1010][1010];
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=2;i<n;i++)
		for(j=2;j<n;j++)
			if(a[i][j]=='X'&&a[i+1][j+1]=='X'&&a[i-1][j-1]=='X'&&a[i-1][j+1]=='X'&&a[i+1][j-1]=='X')
				has++;
	cout<<has<<"\n";
}