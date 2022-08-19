#include<iostream>
#include<string>

using namespace std;

int N;
string S;

int main() {
	cin >> S;
	N = S.size();
	int res = 1;
	for(int i = N - 1; i > 0; i--) {
		if(S[i] != '0') {
			if(2 * i < N || (2 * i == N && S[i] > S[0])) {
				break;
			} else  {
				res++;
				N = i;
			}
		}
	}
	cout << res << '\n';
	return 0;
}