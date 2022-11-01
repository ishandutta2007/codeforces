#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int a,b,c,n;x--;)
	{
		cin>>a>>b>>c>>n;
		if(a>b)a^=b,b^=a,a^=b;
		if(b>c)b^=c,c^=b,b^=c;
		n-=2*c-a-b;
		cout<<(n>=0&&n%3==0?"YES\n":"NO\n");
	}
	return 0;
}