#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string c;
	int T;
	cin>>T;
	while(T--){
		cin>>c;
		if(c.length()<11){
			cout<<c<<endl;
			continue;
		}
		else cout<<c[0]<<c.length()-2<<c[c.length()-1]<<endl;
	}
    return 0;
}