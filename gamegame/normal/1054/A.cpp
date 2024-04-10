#include<iostream>
using namespace std;
int x,y,z,p,q,r;
int main(){
	ios::sync_with_stdio(false);
	cin >> x >> y >> z >> p >> q >> r;
	int num1=abs(y-x)*p;
	int num2=abs(x-z)*q+abs(x-y)*q+r*3;
	if(num2<=num1){
		cout << "YES\n";
	}
	else cout << "NO\n";
}