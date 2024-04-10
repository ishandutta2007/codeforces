#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int s[111] = {0}, n, x, S, T;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x, s[i] = s[i - 1] + x;
	cin >> S >> T;
	if (S > T) swap(S, T);
	cout << min(s[T - 1] - s[S - 1], s[n] - s[T - 1] + s[S - 1]) << endl;
}