#include <iostream>
#include <string>

using namespace std;

int muv, i;
int main() {
	int N, M, K; cin >> N >> M >> K;
	if (K < M)
		M = N;
	else
		M = 1;
	string aux;
	cin >> aux; cin >> aux;
	if (aux == "head")
		muv = -1;
	else
		muv = 1;
	if (K == N && muv == 1)
		muv = -1;
	if (K == 1 && muv == -1)
		muv = 1;
	string s;
	cin >> s;
	
	//
	for (i = 0; i < s.size(); ++i)
		if (s[i] == '1') {
            K += muv;
			if (K == N)
				muv = -1;
			if (K == 1)
				muv = 1;
			if ((muv == 1 && K != 1) || K == N)
				M = 1;
			else
				M = N;
       	}
		else {
			K += muv;
			if (K == N)
				muv = -1;
			if (K == 1)
				muv = 1;
			if (K == M) {
				cout << "Controller " << i + 1;
				return 0;
			}
		}
	cout << "Stowaway";
}