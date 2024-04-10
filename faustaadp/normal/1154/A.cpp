#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a[99];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	sort(a+1,a+1+4);
	cout<<a[4]-a[1]<<" "<<a[4]-a[2]<<" "<<a[4]-a[3]<<"\n";
}