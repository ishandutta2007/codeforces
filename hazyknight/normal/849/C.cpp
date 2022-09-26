#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int k,id;

int main()
{
	cin >> k;
	if (k == 0)
		cout << 'a' << endl;
	while (k)
	{
		int cnt = 0;
		for (int i = 1;;i++)
		{
			cnt += i;
			if (cnt + i + 1 > k)
			{
				k -= cnt;
				for (int j = 1;j <= i + 1;j++)
					cout << char('a' + id);
				id++;
				break;
			}
		}
	}
	cout << endl;
	return 0;
}