#include <iostream>
using namespace std; 
int main(int argc, char** argv) {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if(d-a-b+c<=0||c>a||c>b)
	{
		cout << -1;
	}
	else cout << d-a-b+c;
	return 0;
}