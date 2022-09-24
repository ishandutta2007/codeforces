#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int now;
	cin>>now;
	for(int i=1;i<=3;i++){
		int a,b;
		cin>>a>>b;
		if(now==a)now=b;
		else if(now==b)now=a;
	}   
	cout<<now;
}