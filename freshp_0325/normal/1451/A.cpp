#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int n;
		cin>>n;
		if(n==1)	cout<<0<<endl;
		else if(n==2)	cout<<1<<endl;
		else if(n==3)	cout<<2<<endl;
		else if(n&1)	cout<<3<<endl;
		else	cout<<2<<endl; 
	}
	return 0;
}