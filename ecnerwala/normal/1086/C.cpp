#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
int K;
int N;
char S[MAXN];
char A[MAXN];
char B[MAXN];

const int MAXK = 30;
bool used[MAXK];
int choice[MAXK];

void printRes() {
	cout << "YES\n";
	for (int v = 0, j = 0; v < K; v++) {
		if (choice[v] == -1) {
			while (used[j]) j++;
			choice[v] = j;
			used[j] = true;
		}
		cout << char(choice[v]+'a');
	}
	cout << '\n';
}

void go() {
	// for each equal character, you must take it
	// for each unequal character, you can pick
	memset(choice, -1, sizeof(choice));
	memset(used, 0, sizeof(used));
	int i = 0;
	while (i < N && A[i] == B[i]) {
		int s = (S[i] - 'a');
		int a = (A[i] - 'a');
		int b = (B[i] - 'a');
		assert(0 <= s && s < K);
		assert(0 <= a && a < K);
		assert(0 <= b && b < K);
		assert(a <= b);
		assert(a == b);
		if (choice[s] == -1) {
			if (used[a]) {
				cout << "NO\n";
				return;
			}
			used[a] = true;
			choice[s] = a;
		}
		if (choice[s] != a) {
			cout << "NO\n";
			return;
		}
		i++;
	}
	if (i == N) {
		printRes();
		return;
	} else {
		// now we choose 
		assert(A[i] < B[i]);
		for (int v = A[i] - 'a'; v <= B[i] - 'a'; v++) {
			if (!(choice[S[i] - 'a'] == v || (choice[S[i] - 'a'] == -1 && !used[v]))) {
				continue;
			}
			bool didSet = (choice[S[i] - 'a'] == -1);
			if (didSet) {
				choice[S[i] - 'a'] = v;
				used[v] = true;
			}
			assert(choice[S[i] - 'a'] == v);
			if (A[i] - 'a' < v && v < B[i] - 'a') {
				printRes();
				return;
			}
			if (v == A[i] - 'a') {
				assert(v < B[i] - 'a');
			} else if (v == B[i] - 'a') {
				assert(v > A[i] - 'a');
			} else assert(false);

			int oldChoice[MAXK];
			bool oldUsed[MAXK];
			memcpy(oldChoice, choice, sizeof(choice));
			memcpy(oldUsed, used, sizeof(used));
			bool good = true;
			for (int j = i+1; j < N; j++) {
				if (choice[S[j] - 'a'] == -1) {
					if (v == A[i] - 'a') {
						for (int w = K-1; w >= 0; w--) {
							if (used[w]) {
								continue;
							}
							used[w] = true;
							choice[S[j] - 'a'] = w;
							break;
						}
					} else if (v == B[i] - 'a') {
						for (int w = 0; w < K; w++) {
							if (used[w]) {
								continue;
							}
							used[w] = true;
							choice[S[j] - 'a'] = w;
							break;
						}
					} else assert(false);
					assert(choice[S[j] - 'a'] != -1);
				}
				if (v == A[i] - 'a') {
					if (choice[S[j] - 'a'] > A[j] - 'a') {
						good = true;
						break;
					} else if (choice[S[j] - 'a'] < A[j] - 'a') {
						good = false;
						break;
					}
				} else if (v == B[i] - 'a') {
					if (choice[S[j] - 'a'] < B[j] - 'a') {
						good = true;
						break;
					} else if (choice[S[j] - 'a'] > B[j] - 'a') {
						good = false;
						break;
					}
				} else assert(false);
			}
			if (good) {
				printRes();
				return;
			}
			memcpy(used, oldUsed, sizeof(used));
			memcpy(choice, oldChoice, sizeof(choice));
			if (didSet) {
				choice[S[i] - 'a'] = -1;
				used[v] = false;
			}
		}
		cout << "NO\n";
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> K >> S >> A >> B;
		N = int(strlen(S));
		go();
	}

	return 0;
}