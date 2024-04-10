#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string a,b;

int main()
{
	cin>>a;cin.get();
	cin>>b;
	reverse(b.begin(),b.end());
	if(a!=b)
		cout<<"NO";
	else
		cout<<"YES";
}