#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M, K; cin >> M >> N >> K;
	
	vector<int> div;
	for (int i = 1; i * i <= N; ++i)
		if (N % i == 0) {
			div.push_back(i);
			if (i != N / i)
				div.push_back(N / i);
		}
	
	sort(div.begin(), div.end());
	
	vector<int> mex(div.size());
	
	for (int j = 0; j < mex.size(); ++j) {
		vector<int> grundy(div.size(), 0);

		for (int i = 0; div[i] < div[j]; ++i)
			if (div[i] >= K && div[j] % div[i] == 0) 
				grundy[((div[j] / div[i]) % 2) * mex[i]] = 1;
		
		for (int i = 0; i < grundy.size(); ++i)
			if (grundy[i] == 0) {
				mex[j] = i;
				break;
		}
		
		cerr << div[j] << " -> " << mex[j] << "\n";
	}

	cout << (((M % 2) * mex.back()) ? "Timur" : "Marsel");
}