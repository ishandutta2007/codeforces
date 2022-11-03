#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
	int n,k,t;
	cin>>n>>k>>t;
	
	if(t<k || t==k) 
	
	cout<<t;
	else if(t>k && t<=n)
	cout<<k;
	else if(t>n)
	cout<<k-(t-n);
	return 0;
}