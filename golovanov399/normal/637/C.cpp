#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int d = 6;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			int tmp = 0;
			for (int ij = 0; ij < 6; ij++){
				if (a[i][ij] != a[j][ij])
					tmp++;
			}
			d = min(d, tmp);
		}
	}

	if (n == 1){
		cout << 6;
	} else {
		cout << (d - 1) / 2;
	}
	cout << "\n";

	return 0;
}