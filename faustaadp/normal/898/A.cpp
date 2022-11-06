#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int main()
{
	cin>>n;
	if(n%10>5)
		n+=10;
	n-=n%10;
	cout<<n<<"\n";
}