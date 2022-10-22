#include <iostream>
#include <string>

using namespace std;

int main() {
	string colors = "ROYGVBI";
	string answer;

	int N; cin >> N;
	if ((N - 1) % 7 + 1 >= 4) {
		for (int i = 0; i < N % 7; ++i)
			answer += colors[i];
		N -= N % 7;
	} else { 
		N -= 7;
		if (N % 7 == 1) {
		answer = "ROYGRVBI";
	} else if (N % 7 == 2) {
		answer = "ROYGROVBI";
	} else
		answer = "ROYGROYVBI";
	}
	N -= N % 7;
	for (int i = 0; i < N; i += 7)
		answer += colors;
	cout << answer << "\n";
}