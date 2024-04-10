#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,x,a=0,b=2333;
	for(cin>>n;n--;)cin>>x,a=max(a,x),b=min(b,x);
	cout<<((a+b)>>1);
}