#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
int N;
int K;
int phi[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		phi[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i+i; j <= N; j += i) {
			phi[j] -= phi[i];
		}
	}

	// either pick the K lowest phi + 2 or pick the K lowest odd phi + 1
	
	vector<int> all;
	for (int i = 3; i <= N; i++) {
		all.push_back(phi[i]);
	}
	nth_element(all.begin(), all.begin() + K, all.end());
	long long vall = 2;
	for (int i = 0; i < K; i++) {
		vall += all[i];
	}

	vector<int> odd;
	for (int i = 3; i <= N; i += 2) {
		odd.push_back(phi[i]);
	}
	if (int(odd.size()) >= K) {
		nth_element(odd.begin(), odd.begin() + K, odd.end());
		long long vodd = 1;
		for (int i = 0; i < K; i++) {
			vodd += odd[i];
		}
		vall = min(vall, vodd);
	}
	cout << vall << '\n';


	return 0;
}