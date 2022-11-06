#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,tot,p1,p2,p3=0;
	cin>>a>>b;
	p1=(a/5)*(b-(b%5));
	p2=(a%5)*(b/5)+(b%5)*(a/5);
	if(a%5+b%5>=5)
	p3=(a%5+b%5)-4;
	tot=p1+p2+p3;
//	cout<<p1<<" "<<p2<<" "<<p3<<endl;
	cout<<tot<<endl;	
	return 0;
}