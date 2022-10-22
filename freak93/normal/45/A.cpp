#include<fstream>
#include<iostream>
#include<string>

using namespace std;

string list[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},aux;
int n,x;
int main()
{
	cin>>aux;
	for(x=0;x<12;++x)
		if(list[x]==aux)
			break;
	cin>>n;
	x=(x+n)%12;
	cout<<list[x];
}