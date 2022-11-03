#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	int check1=0,check2=0,check3=0,check4=0;
	for(int i=0;i<n;i++)
	{
		string t;
		cin>>t;
		if(t==s)
		{cout<<"YES";
		return 0;
	}
		if(t[1]==s[0])
		check1++;
		if(t[0]==s[1])
		check2++;
	}
	if(check1!=0 and check2!=0)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}