#include<iostream>
using namespace std;
int f(string a)
{
	int as=a.size(),k=0;
	for(int i=1;i<as;i++)
	{
		if(a[i]>a[0])break;
		if(a[i]<a[0])
		{
			k=1;
			break;
		}
	}
	return (as-1)*9+(k?a[0]-49:a[0]-48);
}
int main()
{
	int x;
	cin>>x;
	for(string a;x--;)
	{
		cin>>a;
		cout<<f(a)<<endl;
	}
	return 0;
}