#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	if(n%10>5)
	  cout<<n-n%10+10;
	else
	  cout<<n-n%10;
	return 0;
}