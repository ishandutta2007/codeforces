#include<iostream>
using namespace std;
int main(){
	long long A,B,x,y,z;
	cin>>A>>B>>x>>y>>z;
	cout<<(2*x+y>A?2*x+y-A:0)+(3*z+y>B?3*z+y-B:0);
}