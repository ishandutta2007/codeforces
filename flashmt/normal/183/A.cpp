#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int n,x=1,y=1;
	cin >> n;
	while (n--) 
	{
		cin >> s;
		if (s=="ULDR") x++, y++;
		else
			if (s=="UR" || s=="DL") x++;
			else y++;
	}
	cout << 1LL*x*y << endl;
}