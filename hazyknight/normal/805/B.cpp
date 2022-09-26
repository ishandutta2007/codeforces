#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		if ((i & 3) <= 1)
			cout << 'a';
		else
			cout << 'b'; 
	}
	cout << endl;
	return 0;
}