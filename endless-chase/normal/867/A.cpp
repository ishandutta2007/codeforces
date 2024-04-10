#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n>>s;
	int snum=0,fnum=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		continue;
		if(s[i]=='F' and s[i-1]=='S')
		fnum++;
		if(s[i]=='S' and s[i-1]=='F')
		snum++;
	}
	if(fnum>snum)
	cout<<"YES";
	else 
	cout<<"NO";
	return 0;
 }