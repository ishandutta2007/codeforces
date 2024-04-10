#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#define x first
#define y second

using namespace std;

int main() {
	int N, K; cin >> N >> K;
	vector< pair<int, int> > A, B;
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		if (y == 1)
			A.push_back(make_pair(x, i + 1));
		else
			B.push_back(make_pair(x, i + 1));
	}
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());

	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	

	int carts = 0;
	int i;
	long long answer = 0;
	stringstream cast;
	for (i = 0; i < K - 1 && i < static_cast<int>(A.size()); ++i) {
		++carts;
		answer += A[i].first;
		cast << "1 " << A[i].second << "\n";
	}

	vector<int> pos;
	for (;i < static_cast<int>(A.size()); ++i) {
		pos.push_back(A[i].second);
		answer += A[i].first * 2;
	}

	bool caset = false;
	if (A.size() >= K)
		caset = true;
	if (carts < K - 1)
		for (i = 0; i < static_cast<int>(B.size()) && carts < K - 1; ++i, ++carts) {
			cast << "1 " << B[i].second << "\n";
			answer += B[i].first * 2;
		}
	else
		i = 0;
	for (; i < static_cast<int>(B.size()); ++i) {
		pos.push_back(B[i].second);
		answer += B[i].first * 2;
	}

	if (caset == true)
		if (B.size() > 0)
			answer -= min(B.back().first, A.back().first);
		else
			answer -= A.back().first;

	cast << pos.size() << " ";
	for (int i = 0; i < pos.size(); ++i)
		cast << pos[i] << " ";
	cout << answer / 2 << "." << (answer % 2) * 5 << "\n";
	cout << cast.str();
}