#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	
	int notFolded = n - count(s.begin(), s.end(), 'F');
	int in = count(s.begin(), s.end(), 'I');
	
	if (in > 1) cout << 0 << endl;
	else
		if (in == 1) cout << 1 << endl;
		else cout << notFolded << endl;
}