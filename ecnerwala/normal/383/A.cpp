#include<iostream>

using namespace std;

typedef long long ll;

const int MAXN = 4e5;

int N;
int A[MAXN];

ll go() {
	ll res = 0;
	ll cnt = 0;
	for(int i = 0; i < N; i++) {
		if(A[i]) {
			cnt ++;
		} else {
			res += cnt;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << go() << '\n';
}