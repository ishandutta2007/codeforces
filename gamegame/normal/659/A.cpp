#include<iostream>
using namespace std;
int main(){
	int n,a,b;
	cin >> n >> a >> b;
	b=((b+n)%n+n)%n;
	cout << (a+b-1)%n+1 << endl;
}