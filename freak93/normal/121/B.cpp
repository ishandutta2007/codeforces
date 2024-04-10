#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int N, K;
	string a;
	cin >> N >> K >> a;
	for (int i = 1; i < N && K > 0; ++i)
		if (a[i - 1] == '4' && a[i] == '7')
			if (i % 2)
				a[i] = '4', --K;
			else
				if (i > 1 && a[i - 2] == '4')
					if (K % 2)
						a[i - 1] = '7', K = 0;
					else
						break;
				else
					a[i - 1] = '7', --K;
	cout << a;
}