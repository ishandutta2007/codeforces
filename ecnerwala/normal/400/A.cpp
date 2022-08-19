#include<iostream>

using namespace std;

char S[20];
int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> S;
		int num = 0;
		for(int a = 1; a <= 12; a++) {
			if(12 % a == 0) {
				int b = 12 / a;
				int v = (1 << 13) - 1;
				for(int i = 0; i < a; i++) {
					int r = 0;
					for(int j = 0; j < b; j++) {
						if(S[i * b + j] == 'X') r++;
						r *= 2;
					}
					v = v & r;
				}
				if(v) num++;
			}
		}
		cout << num;
		for(int a = 1; a <= 12; a++) {
			if(12 % a == 0) {
				int b = 12 / a;
				int v = (1 << 13) - 1;
				for(int i = 0; i < a; i++) {
					int r = 0;
					for(int j = 0; j < b; j++) {
						if(S[i * b + j] == 'X') r++;
						r *= 2;
					}
					v = v & r;
				}
				if(v) cout << ' ' << a << 'x' << b;
			}
		}
		cout << '\n';
	}
}