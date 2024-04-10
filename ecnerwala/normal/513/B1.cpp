#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll M;

int main() {
	cin >> N >> M;
	M--;
	deque<int> res;
	res.push_back(N);
	for(int i = N - 1; i > 0; i--) {
		if(M % 2) {
			res.push_back(i);
		} else {
			res.push_front(i);
		}
		M /= 2;
	}
	for(int i : res) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}