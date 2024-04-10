#include<iostream>
#include<cstdio>
using namespace std;
int T,x;
int sol(int x)
{
	if(x<10)return x;if(x<=17)return 10*(x-9)+9;if(x<=24)return 100*(x-17)+89;if(x<=30)return 1000*(x-24)+789;
	if(x<=35)return 10000*(x-30)+6789;if(x<=39)return 100000*(x-35)+56789;if(x<=42)return 1000000*(x-39)+456789;
	if(x<=44)return 10000000*(x-42)+3456789;return 123456789;
}
int main(){cin>>T;while(T--)cin>>x,cout<<(x<=45?sol(x):-1)<<endl;return 0;}