#include<bits/stdc++.h>
using namespace std;

int N;
int M[200];
int R[200];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) { cin >> M[i]; }
	for(int i = 0; i < N; i++) { cin >> R[i]; }

	int res = 0;
	for(int d = 0; d < 720720; d++) {
		bool good = false;
		for(int i = 0; i < N; i++) {
			if(d % M[i] == R[i]) good = true;
		}
		res += good;
	}
	cout << fixed << setprecision(6) << (double(res) / 720720) << '\n';

	return 0;
}