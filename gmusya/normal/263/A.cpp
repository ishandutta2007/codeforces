#include <iostream>
#include <vector>

using namespace std;

int main() {
	int answer;
	int arr[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				answer = abs(2 - i) + abs(2 - j);
		}
	cout << answer;
	return 0;
}