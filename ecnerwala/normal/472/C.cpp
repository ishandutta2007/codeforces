#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
string S[MAXN][2];

int P[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> S[i][0] >> S[i][1];
		if(S[i][1] < S[i][0]) {
			swap(S[i][0], S[i][1]);
		}
	}
	for(int i = 0; i < N; i++) {
		cin >> P[i]; P[i] --;
	}
	bool good = true;
	string s = "";
	for(int i = 0; i < N; i++) {
		int p = P[i];
		if(S[p][0] > s) s = S[p][0];
		else if(S[p][1] > s) s = S[p][1];
		else {
			good = false;
			break;
		}
	}
	cout << (good ? "YES" : "NO") << '\n';
	return 0;
}