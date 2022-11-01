#include <iostream>

using namespace std;

int main() {
	int k, r;
	cin >> k >> r;
	int answer = 1;
	while (answer * k % 10 != r && answer * k % 10 != 0)
		answer++;
	cout << answer;
	return 0;
}