#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int lol=0;
	
	lol=max(1,abs(a-c))+max(1,abs(b-d))+2;
	lol*=2;
	cout<<lol<<endl;
}