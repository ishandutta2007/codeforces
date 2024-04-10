#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,h,i,o,a;
	long long t=0;
	cin>>n>>h;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if (a>h)
		t+=2;
		else
		t+=1;
	}
	cout<<t<<endl;
	return 0;
}