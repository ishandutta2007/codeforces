#include<bits/stdc++.h>
using namespace std;

int n, t;
bool arr[100][100];
bool flag = 0;

int q(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl << flush;
	int t;
	cin >> t;
	if(t == -1) exit(0);
	return !t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	arr[1][1] = 1;
	arr[2][1] = arr[1][2] ^ q(1, 2, 2, 3) ^ q(2, 1, 2, 3);

	for(int i=3; i<=n; i++) {
		arr[i][1] = arr[i-2][1] ^ q(i-2, 1, i, 1);
		arr[1][i] = arr[1][i-2] ^ q(1, i-2, 1, i);
	}

	for(int i=2; i<=n; i++) {
		for(int j=2; j<=n; j++) {
			arr[i][j] = arr[i-1][j-1] ^ q(i-1, j-1, i, j);
		}
	}

	for(int i=1; i+2<=n; i+=2) {
		if(arr[i][i] ^ arr[i+2][i+2]) {
			if(!((arr[i][i] ^ arr[i][i+2]) ^ (arr[i][i+1] ^ arr[i+1][i+2]))) {
				flag = (arr[i][i] ^ q(i, i, i+1, i+2)) ^ arr[i+1][i+2];
			}
			else flag = (arr[i+2][i+2] ^ q(i, i+1, i+2, i+2)) ^ arr[i][i+1];
			break;
		}
	}

	cout << "!" << endl << flush;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if((i + j) % 2) arr[i][j] ^= flag;
			cout << arr[i][j];
		}
		cout << endl << flush;
	}

	//cout << cnt;
}