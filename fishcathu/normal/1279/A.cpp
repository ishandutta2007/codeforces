#include<iostream>
using namespace std;
int main()
{ 
	int x;
	cin>>x;
	for(int a,b,c;x--;)
	{
		cin>>a>>b>>c;
		if(a>b)a^=b,b^=a,a^=b;
		if(b>c)b^=c,c^=b,b^=c;
		if(a+b+1>=c)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}