#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
long long rev(long long x){
	long long t=0;
	while(x){
		t=10*t+x%10;
		x/=10;
	}
	return t;
}
int main()
{
	long long x;

	cin>>x;
	while(x%10==0){
		x/=10;
	}
	
	if(x==rev(x)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}