#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll L,R,i;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>L>>R;
	cout<<"YES\n";
	for(i=L;i<=R;i+=2)
        cout<<i<<" "<<i+1<<"\n";
}