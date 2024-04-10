#include <bits/stdc++.h>

using namespace std;
/*input
8
*/
/*input
2
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int b = __builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount((n - 2) *(n - 1) *((n+1) % 2))))));
	cout << char('N' + ('Y' - 'N') * b);
	cout << char('O' + ('E' - 'O') * b);
	cout << char('\n' + ('S' - '\n') * b);
}