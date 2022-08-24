#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
bool a,b,c,d;
//&^|
//&|^
int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b >> c >> d;
	bool e=a^b;
	bool f=c|d;
	bool g=b&c;
	bool h=a^d;
	bool x=e&f;
	bool y=g|h;
	cout << (x^y) << '\n';
}