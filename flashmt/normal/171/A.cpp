#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string a,b;
	int x,y;
	cin >> a >> b;
	reverse(b.begin(),b.end());	
	stringstream ss;
	ss << a; ss >> x; ss.clear();
	ss << b; ss >> y;
	cout << x+y << endl;
}