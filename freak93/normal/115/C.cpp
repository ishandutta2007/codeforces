#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<string> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	
	vector<int> markh(N, 0), markv(M, 0);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (a[i][j] == '1' || a[i][j] == '2')
				markh[i] |= (2 - j % 2);
			else
				if (a[i][j] == '3' || a[i][j] == '4')
					markh[i] |= (2 - (j + 1) % 2);

			if (a[i][j] == '1' || a[i][j] == '4')
				markv[j] |= (2 - i % 2);
			else
				if (a[i][j] == '2' || a[i][j] == '3')
					markv[j] |= (2 - (i + 1) % 2);
		}
	
	int rez = 1;
	for (int i = 0; i < N; ++i)
		if (markh[i] == 3)
			rez = 0;
		else
			if (markh[i] == 0)
				rez = (rez * 2) % 1000003;
	
	for (int i = 0; i < M; ++i)
		if (markv[i] == 3)
			rez = 0;
		else
			if (markv[i] == 0)
				rez = (rez * 2) % 1000003;
	
	cout << rez;
}