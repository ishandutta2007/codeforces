#include <iostream>
#include <fstream>

using namespace std;

int d[10];
int mort[1000000];
int N;

int main() {
	for (int i = 0; i < 4; ++i)
		cin >> d[i];
	
	cin >> N;

	for (int i = 0; i < 4; ++i)
		for (int j = d[i]; j <= N; j += d[i])
			mort[j] = 1;
	
	int answer = N;
	for (int i = 1; i <= N; ++i)
		answer -= mort[i];
	
	cout << N - answer;
}