#include<iostream>

using namespace std;


int main() {
	int N, X; cin >> N >> X;
	int S = 0;
	for(int i = 0; i < N; i++) {
		int v; cin >> v;
		S += v;
	}
	if(S < 0) S = -S;
	cout <<  (S + X - 1) / X << '\n';
	return 0;
}