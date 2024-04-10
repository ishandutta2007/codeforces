#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

char gArr[5040][5], aArr[10000][5];
int gCnt = 0, aCnt = 0;

inline bool generate() {
	for (char a = '0'; a <= '9'; a++) {
		for (char b = '0'; b <= '9'; b++) {
			if (a != b) {
				for (char c = '0'; c <= '9'; c++) {
					if (a != c && b != c) {
						for (char d = '0'; d <= '9'; d++) {
							if (a != d && b != d && c != d) {
								gArr[gCnt][0] = a;
								gArr[gCnt][1] = b;
								gArr[gCnt][2] = c;
								gArr[gCnt][3] = d;
								gCnt++;
							}
						}
					}
				}
			}
		}
	}
	for (char a = '0'; a <= '9'; a++) {
		for (char b = '0'; b <= '9'; b++) {	
			for (char c = '0'; c <= '9'; c++) {
				for (char d = '0'; d <= '9'; d++) {
					aArr[aCnt][0] = a;
					aArr[aCnt][1] = b;
					aArr[aCnt][2] = c;
					aArr[aCnt][3] = d;
					aCnt++;
				}
			}
		}
	}
	return true;
}
bool generated = generate();

inline void count(int gId, int aId, int& A, int& B) {
	A = B = 0;
	for (int i = 0; i < 4; i++) {
		if (gArr[gId][i] == aArr[aId][i]) {
			A++;
			continue;
		}
		for (int j = 0; j < 4; j++) {
			if (gArr[gId][i] == aArr[aId][j]) {
				B++;
				break;
			}
		}
	}
}

/*namespace Grader {
	int _guess;
	int cnt;

	void init() {
		_guess = -1;
		while (_guess < 0) {
			string s; cin >> s;
			for (int i = 0; i < gCnt; i++) {
				if (gArr[i] == s) {
					_guess = i;
					break;
				}
			}
			if (_guess < 0) {
				cout << "Wrong number. Please try again." << endl;
			}
		} 
		cnt = 0;
	}
	
	void ask(int aId, int& A, int& B) {
		if (cnt == 7) {
			cout << "Guess failed" << endl;
			exit(1);
		}
		cnt++;
		count(_guess, aId, A, B);
		cout << aArr[aId] << "|" << A << "A" << B << "B" << endl;
		if (A == 4) {
			cout << "Success" << endl;
			exit(0);
		}
	}
};*/

namespace Grader {
	void init() {	
	}
	
	void ask(int aId, int& A, int& B) {
		cout << aArr[aId] << endl;
		cin >> A >> B;
		if (A == 4) {
			exit(0);
		}
	}
};

int main() {
	Grader::init();
	vector<int> tries(gCnt);
	for (int i = 0; i < (int)tries.size(); i++) {
		tries[i] = i;
	}
	int cnts[5][5];
	for (int i = 0; i < 7; i++) {
		int bestJ = -1, bestSz = -1;
		for (int j = 0; j < aCnt; j++) {
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 5; l++) {
					cnts[k][l] = 0;
				}
			}
			for (int k = 0; k < (int)tries.size(); k++) {
				int A, B;
				count(tries[k], j, A, B);		
				cnts[A][B]++;	
			}
			int gCnt = 0;
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 5; l++) {
					if (cnts[k][l] != 0) {
						gCnt++;
					}
				}
			}
			if (gCnt == 1 && cnts[4][0] != 0) {
				gCnt = 42;
			}
			if (gCnt > bestSz) {
				bestSz = gCnt;
				bestJ = j;
			} 
		}
		int A, B;
		Grader::ask(bestJ, A, B);
		vector<int> newTries;
		for (int j = 0; j < (int)tries.size(); j++) {
			int nA, nB;
			count(tries[j], bestJ, nA, nB);
			if (nA == A && nB == B) {
				newTries.push_back(tries[j]);
			}
		}
		tries = newTries;
	}
	return 42;
}