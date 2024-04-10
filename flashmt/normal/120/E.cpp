#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int test,n;
	cin >> test;
	while (test--)
	{
		cin >> n;
		cout << 1-(n&1) << endl;
	}
}