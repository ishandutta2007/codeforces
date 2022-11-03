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
	int n,x,b=0,c,f=0;
	cin>>n>>x; 
	int a[110];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<x) b++;
		else if(a[i]==x) f++;
	}
	c=x-b+f;
	cout<<c;
	return 0;
}