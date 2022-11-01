#include<iostream>
using namespace std;
int main()
{
	int x;
	for (cin>>x; x--;)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << a * 1ll + b + c - 1<<endl;
	}
	return 0;
}