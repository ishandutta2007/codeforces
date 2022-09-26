#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a,b;
int ans;

int main()
{
	cin >> a >> b;
	while (a <= b)
	{
		ans++;
		a *= 3;
		b <<= 1;
	}
	cout << ans << endl;
	return 0;
}