#include <iostream>

using namespace std;

int N;
int a[305][305];
int b[305], where[305];

int main() {
	cin >> N;
	for (int i = 1; i <= N; ++i) 
		for (int j = 1; j <= N; ++j)
			cin >> a[i][j];
	
	for (int i = 1; i <= N; ++i)
		cin >> b[i], where[b[i]] = i;
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			if (a[i][j] != i) {
				int k;
				for (k = 1; k < a[i][j]; ++k)
					if (k != i && where[k] < where[a[i][j]])
						break;
				if (k == a[i][j]) {
					cout << a[i][j] << " ";
					break;
				}
			}
	}
}